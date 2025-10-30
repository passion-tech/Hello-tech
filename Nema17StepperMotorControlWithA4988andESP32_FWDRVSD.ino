// Control Stepper Motor with A4988 and ESP32

#define STEP_PIN 18   // Step pin connected to A4988 STEP
#define DIR_PIN 19    // Direction pin connected to A4988 DIR
#define ENABLE_PIN 21 // Optional, connected to A4988 ENABLE

int stepsPerRevolution = 400; // Adjust based on your motor

void setup() {
  Serial.begin(115200);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);

  digitalWrite(ENABLE_PIN, LOW); // Enable driver (LOW = ON)
  Serial.println("Stepper Motor Test Start");
}

void loop() {
  // Rotate clockwise
  digitalWrite(DIR_PIN, HIGH);
  stepMotor(stepsPerRevolution); // One full rotation
  delay(1000);

  // Rotate counterclockwise
  digitalWrite(DIR_PIN, LOW);
  stepMotor(stepsPerRevolution);
  delay(1000);
}

void stepMotor(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000); // Control speed (lower = faster)
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
}
