#include <Servo.h>
 Servo servo;

void setup() {
  servo.attach(8);
  servo.write(0);
  delay(2000);
  
  // put your setup code here, to run once:

}

void loop() {
  servo.write(180);
  delay(1000);
  servo.write(90);
  delay(1000);
  // put your main code here, to run repeatedly:

}
