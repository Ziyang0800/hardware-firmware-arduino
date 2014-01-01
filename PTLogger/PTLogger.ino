/*
  SD card datalogger
 
 This example shows how to log data from three analog sensors 
 to an SD card using the SD library.
 	
 This example code is in the public domain.
 	 
 */

#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
#include <SPI.h>
//#include <SD.h>
#include <avr/pgmspace.h>
#include "main.h"
#include "display.h"
#include "events.h"
#include "measure.h"
#include "data.h"
#include "menu.h"
#include "statemanager.h"
#include "edit.h"

void setup()
{  
  Wire.begin();  

  lcd.begin(16, 2);
 
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  
  
  if (! rtc.isrunning()) {
    lcd.print_f(1, 1, PSTR("RTC is NOT running!"));
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
  }
  
  LogEvents.start();
}

void loop() {  
  Events.doHandleEvents();
  MeasureEvents.doHandleEvents();
  LogEvents.doHandleEvents();
  StateMachine.doHandleStates();
//  PT1000.doMeasure();  
  LogData.process();  
}

byte showMenu(byte input) {
  
  byte group;
  byte state;
  
  PGM_P menuText;
  static byte enter = 0;
  static byte count = 1;

  if(!enter) { 
    enter = true;
    
    lcd.clear();
    
    for (byte i=0; (group = pgm_read_byte(&menu_state[i].group)); i++) {
      if (group == StateMachine.stateGroup) {
        state = pgm_read_byte(&menu_state[i].state);
        menuText = (PGM_P)pgm_read_word(&menu_state[i].pText);
        if (menuText != NULL) {
          if (state == group) {          
            lcd.print_f(0, 0, menuText);   // draw menu title                     
          }
          
          state = pgm_read_byte(&menu_state[i + count].state);
          menuText = (PGM_P)pgm_read_word(&menu_state[i + count].pText);
          lcd.print_f(0, 1, menuText);
          
          if (group != pgm_read_byte(&menu_state[i + count + 1].group)) {
            count = 0;
          }
          break;
        }
      }
    }
  }
  
  if (input == KEY_PLUS) {
    count++;
    enter = 0;
  } else if (input == KEY_ENTER) {
    enter = 0;
    StateMachine.stateGroup = state;
    return StateMachine.stateGroup;
  }
  
  return StateMachine.state;
}

byte exitMainMenu(byte input) {
  return ST_MAIN;
}

byte exitDateTimeMenu(byte input) {
  return ST_MAIN_MENU;
}

byte mainScreen(byte input) {
  static byte enter = 0;
  if(!enter) {  
    lcd.clear();
    lcd.print_f(0, 0, PSTR("Logger V1.0"));
    enter = true;
  }


  char buffer[9]= { "00:00:00" };  
  if (Events.bT1000MS) {
    DateTime dt = rtc.now();
    itochars(dt.hour(), &buffer[0], 2);
    itochars(dt.minute(), &buffer[3], 2);
    itochars(dt.second(), &buffer[6], 2);  
    
    lcd.print(0, 1, buffer);
  }


  if (input == KEY_ENTER) {
    enter = false;
    return ST_MAIN_MENU;
  }  
  return ST_MAIN;
}

byte setLogging(byte input) {
  //return LogSettingsScreen.execute(input);
  return ST_MAIN;
}

byte setRtcTime(byte input) {
  static EditTime edTime;
  static byte enter = 0;
  
  if(!enter) {
    lcd.clear();
    lcd.print_f(0, 0, PSTR("Set Time"));
    enter = true;
  }
  
  if (!edTime.editTime(input)) {
    enter = false;
    return ST_MAIN;
  }
  return ST_TIME;
}

byte setRtcDate(byte input) {
  //return EditDateScreen.execute(input);  
  return ST_MAIN;
}

byte temperatureChart(byte input) {
  //return TempChartScreen.execute(input);
  return ST_MAIN;
}

void logError(String s) {
  //displayText(0, 0, 1, s);
}

void itochars(unsigned int value, char buffer[], byte digits) {
  byte i = 0; 
  byte d;
  unsigned int k;
  
  unsigned int P[] = { 1, 10, 100, 1000, 10000 };
  
  k = P[digits-1]; 

  while(i < digits) {
    d = value / k;
    value -= (d * k);
    buffer[i] = d + '0';
    k /= 10;
    i++;
  }
}


    
