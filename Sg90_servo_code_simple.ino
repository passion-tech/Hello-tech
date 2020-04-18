#include <Servo.h>
Servo sg90; 
void setup() {
sg90.attach(3 );   // put your setup code here, to run once:

}

void loop() {
 sg90.write(0);  // put your main code here, to run repeatedly:
 delay(1000); 
  sg90.write(90);
  delay(1000); 
   sg90.write(180);
   delay(3000); 
}
