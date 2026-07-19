#include <Servo.h>

Servo servoX;
Servo servoY;

int xPin = A0;
int yPin = A1;

void setup() {
  servoX.attach(9);
  servoY.attach(10);

  servoX.write(90);  // Center position
  servoY.write(90);

  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);

  int angleX = map(xValue, 0, 1023, 0, 180);
  int angleY = map(yValue, 0, 1023, 0, 180);

  servoX.write(angleX);
  servoY.write(angleY);

  Serial.print("X: ");
  Serial.print(angleX);
  Serial.print("  Y: ");
  Serial.println(angleY);

  delay(15);
}