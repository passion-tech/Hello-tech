// Include the Arduino Stepper Library
#include <Stepper.h>
 
// Define Constants
 
// Number of steps per output rotation
const int STEPS_PER_REV = 200;
const int SPEED_CONTROL = A0;

// The pins used are 1,2,3,4 
// Connected to L298N Motor Driver In1, In2, In3, In4 
// Pins entered in sequence 1-2-3-4 for proper step sequencing
 
Stepper stepper_NEMA17(STEPS_PER_REV, 1, 2, 3, 4);
 
void setup() {
  // nothing to do inside the void setup
}
 
void loop() {
  // read the sensor value:
  int sensorReading = analogRead(SPEED_CONTROL);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    stepper_NEMA17.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    stepper_NEMA17.step(STEPS_PER_REV / 100);
  }
}
