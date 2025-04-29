#include <Servo.h>

const int irSensorPin = 7;  // IR sensor output pin
const int servoPin = 9;     // Servo signal pin

Servo myServo;

void setup() {
  pinMode(irSensorPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0); // Start at 0 degrees
  Serial.begin(9600);
}

void loop() {
  int irValue = digitalRead(irSensorPin);

  if (irValue == LOW) { // Object detected (depending on your sensor, it may be HIGH)
    Serial.println("Object Detected!");
    myServo.write(90); // Rotate to 90 degrees
  } else {
    Serial.println("No object.");
    myServo.write(0); // Return to 0 degrees
  }

  delay(200); // Small delay for stability
}
