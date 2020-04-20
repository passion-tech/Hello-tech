#include <Servo.h>
//Define servo motor
Servo servo1;
Servo servo2;
// Define Servo position jin degrees
int servoPos =0;

void setup() {
 // put your setup code here, to run once:
 //Define servo signal inputs(Digital PWM 3-5);
 servo1.attach(3);
 servo2.attach(5);

}

void loop() {
  // put your main code here, to run repeatedly:
//Scan from 0-180 degrees;
for(servoPos=0; servoPos <180; servoPos++);
{
servo1.write(servoPos);
servo2.write(servoPos);
delay(1000);
}
//scan back from 180 to 0 degrees
for(servoPos =180; servoPos >0; servoPos--)

servo1.write(servoPos);
servo2.write(servoPos);
delay(2000);

}
