// Web ****************************************************************
#include <avr/pgmspace.h>
#include "webpage.h"


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 2, 86); // 192.168.2.86

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

class WebManager {
  public:
    void begin() {
      Ethernet.begin(mac, ip);
      server.begin();
    }
    
    void dispatch() {
      EthernetClient client = server.available();
      if (client) {
        //Serial.println("new client");
        // an http request ends with a blank line
        static boolean currentLineIsBlank = true;
        if (client.connected()) {
          if (client.available()) {
            char c = client.read();
            Serial.write(c);
            // if you've gotten to the end of the line (received a newline
            // character) and the line is blank, the http request has ended,
            // so you can send a reply
            if (c == '\n' && currentLineIsBlank) {
              // send a standard http response header
              client.println("HTTP/1.1 200 OK");
              client.println("Content-Type: text/html");
              client.println("Connection: close");  // the connection will be closed after completion of the response
              //client.println("Refresh: 5");  // refresh the page automatically every 5 sec
              client.println();
              //client.println("<!DOCTYPE HTML>");
              //client.println("<html>");
              
              //client.print("DS1821: ");
              //client.print(Measure.temperature);
              //client.println();
              //client.println(RTC.getSeconds());
              
              //client.println("<br />");
              
             
              //client.println("</html>");
              
              PGM_P page_pointer = Page1;
              
              for(;;) {
                unsigned char b = pgm_read_byte(page_pointer++);
                if (strncasecmp_P("%END",page_pointer,4)==0) {			  
		  break;
	        }
                client.write(b);
              }
              
            }
            if (c == '\n') {
              // you're starting a new line
              currentLineIsBlank = true;
            }
            else if (c != '\r') {
              // you've gotten a character on the current line
              currentLineIsBlank = false;
            }
            
                        
          }
        } else {
          // give the web browser time to receive the data
          //delay(1);
          // close the connection:
          client.stop();          
          Serial.println("client disconnected");
        }
      }
      
    }
};

WebManager Web;
