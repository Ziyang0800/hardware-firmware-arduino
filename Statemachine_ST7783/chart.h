#ifndef _CHARTSH_
#define _CHARTSH_

// Charts ****************************************************************

#define DISPLAYHEIGHT TFTWIDTH
#define DISPLAYWIDTH  TFTHEIGHT
#define MARGIN		    8
#define CHARTHEIGHT   250
#define CHARTWIDTH    240
#define CHART_X       0
#define CHART_Y       75

class Chart {    
  public:
    void drawChart(int8_t values[], byte count, int rangeMin, int rangeMax) {
      int8_t min = rangeMax;
      int8_t max = rangeMin;
      int8_t avg = 0;
			
      LogData.getStat(values, count, &min, &max, &avg);
      
      // fit min, max in range of 10th steps *********
      if(min >= 0) { 
        min = 0;
      } else {
        for (int i = 0; i > rangeMin; i -= 10) {
          if (i < min) {
            min = i;
            break;
          }
        }
      }
      
      if(max <= 0) {
        max = 0;
      } else {
        for (int i = 0; i < rangeMax; i += 10) {
          if (i > max) {
            max = i;
            break;
          }
        }
      }
      
      // range ***************************************
      byte range = max - min;
      byte zero = map(0, min, max, CHARTHEIGHT, CHART_Y);   
      
      // draw y-Grid lines ***************************
      for (int8_t i = min; i <= max; i+=5) {
        byte y = map(i, min, max, CHARTHEIGHT, CHART_Y);
        Display.drawFastHLine(CHART_X , y, CHARTWIDTH, LIGHTGRAY);
       
        char buffer[4] = { "000" };
        bin2asc(abs(i), buffer, 3);          
        Display.displayText(CHART_X + CHARTWIDTH - 3 * TEXTWIDTH - 2 , y - TEXTHEIGHT - 2, 1, buffer, LIGHTGRAY, BLACK);
      }
      
      // draw values *********************************
      byte w = (CHARTWIDTH) / count - 1;
      for (byte i = 0; i < count; i++) {
        byte y = map(values[i], min, max, CHARTHEIGHT, CHART_Y);
        //Serial.println(String(values[i]) + ";" + String(y) + ";" + String(zero));
        if (y < zero) 
          Display.fillRect(i * w + CHART_X, y, w, zero - y, RED);
        else
          Display.fillRect(i * w + CHART_X, zero, w, y - zero, BLUE);
      }
    }

      
		
};

#endif
