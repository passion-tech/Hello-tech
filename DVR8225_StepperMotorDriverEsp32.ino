// Stepper Motor Control (Forward & Reverse)
// Using ESP32 + DRV8825 + NEMA 17

#define STEP_PIN 18
#define DIR_PIN 19

// Steps per revolution (depends on your microstepping setup)
// Example: 200 steps/rev * 16 microsteps = 3200
const int stepsPerRevolution = 800;

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
}

void loop() {
  // ----- FORWARD -----
  digitalWrite(DIR_PIN, HIGH);  // Set direction to forward
  rotateOneRevolution();
  delay(500); // Pause before reversing

  // ----- REVERSE -----
  digitalWrite(DIR_PIN, LOW);   // Set direction to reverse
  rotateOneRevolution();
  delay(500); // Pause before next cycle
}

void rotateOneRevolution() {
  for (int i = 0; i < stepsPerRevolution; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1600);  // Adjust for speed (higher = slower)
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(100);
  }
}
