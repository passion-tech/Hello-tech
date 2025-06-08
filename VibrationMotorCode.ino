#define VIBRATION_PIN 9

void setup() {
  pinMode(VIBRATION_PIN, OUTPUT);
}

void loop() {
  // Turn vibration ON
  digitalWrite(VIBRATION_PIN, HIGH);
  delay(1000); // Vibrate for 1 second

  // Turn vibration OFF
  digitalWrite(VIBRATION_PIN, LOW);
  delay(1000); // Wait for 1 second
}
