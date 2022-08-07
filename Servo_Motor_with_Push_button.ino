 
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servoPin = 9;// this servo pin must be  those with PWM ~


#define STOPpin 6 // push button pin  for STOP any of digital pin
#define CWpin 5 //  push button for CW any of digital pin
#define CCWpin 7 // push button for CCW any of digital pin

int sc[]={106,90, 0};// servo commands are in order if your servo does not stop you need to change stop number. 
        //CCW, STOP,CW
        
String scText[]={"CCW","Stop","CW"};// define texts for 3 action
int statusText;
int CWBS, CCWBS, SBS;
      //CW button status (CWBS)
      //CCW button status (CCWBS)
      //stop button status (SBS)

void setup() {
  Serial.begin(9600);
  pinMode(STOPpin,INPUT_PULLUP);// set pin for push button STOP
  pinMode(CCWpin,INPUT_PULLUP);// set pin for push button CCW  
  pinMode(CWpin,INPUT_PULLUP);// set pin for push button CW
    
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  myservo.write(sc[1]);// send STOP command
  statusText=1;// initial value is STOP
}



void loop() {

    CCWBS = digitalRead(CCWpin);// read status of button CCW
    SBS = digitalRead(STOPpin);// read status of button STOP
    CWBS = digitalRead(CWpin);// read status of button CW
        
    if(CCWBS ==LOW)
    {
      servoCommand(0);
    }else if(SBS ==LOW)
    {
      servoCommand(1);
    }else if(CWBS ==LOW)
    {
      servoCommand(2);
    }
    
  Serial.println(scText[statusText]);
  delay(50);
}// loop 



void servoCommand(int n)
{
   statusText = n;
   myservo.write(sc[n]); 
   Serial.print("Going to  ");
   Serial.print(scText[n]);
   Serial.print( "(");
   Serial.print(sc[n]);
   Serial.println(")");
}
