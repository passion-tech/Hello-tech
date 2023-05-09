#include <SoftwareSerial.h>
#include <stdlib.h>

SoftwareSerial ESP8266(2, 3); // RX, TX
unsigned char check_connection=0;                                      
unsigned char times_check=0;

void setup() {
  Serial.begin(115200);
  ESP8266.begin(115200);  

   ESP8266.print("***VER:");
delay(2000);
ESP8266.println("AT+RST");
 delay(1000);
 ESP8266.println("AT+GMR");
delay(1000);
ESP8266.println("AT+CWMODE=3");
delay(1000);
ESP8266.println("AT+CWLAP");
delay(1000);
}


void loop() 
{
Serial.println("Connecting to Wifi");
   while(check_connection==0)
  {
    Serial.print(".");
  ESP8266.print("AT+CWJAP=\"Unifi\",\"99990000\"\r\n");
  ESP8266.setTimeout(5000);
 if(ESP8266.find("WIFI CONNECTED\r\n")==1)
 {
 Serial.println("WIFI CONNECTED");
 break;
 }
 times_check++;
 if(times_check>3) 
 {
  times_check=0;
   Serial.println("Trying to Reconnect..");
  }
  } 

  while(1);
}
