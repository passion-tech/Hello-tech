#include <AccelStepper.h>

// 4-wire stepper using ULN2003 (4-wire interface)
#define IN1 13
#define IN2 12
#define IN3 14
#define IN4 27

// AccelStepper constructor: Interface type 4 = 4-wire (full step/half step)
AccelStepper stepper(AccelStepper::FULL4WIRE, IN1, IN3, IN2, IN4);

void setup() {
  // set max speed and acceleration
  stepper.setMaxSpeed(800.0);     // try lower/higher to tune
  stepper.setAcceleration(200.0);
  Serial.begin(115200);
}

void loop() {
  // move a certain number of steps (28BYJ-48 has internal gearbox; steps per rev depends on mode)
  stepper.moveTo(4096);           // example: one full (geared) revolution ~4096 half-steps typical
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);

  stepper.moveTo(0);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);
}
