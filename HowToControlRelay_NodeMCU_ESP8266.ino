#define RELAY_PIN D1  // Relay IN pin

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF at start
}

void loop() {
  digitalWrite(RELAY_PIN, LOW);  // Relay ON
  delay(2000);

  digitalWrite(RELAY_PIN, HIGH); // Relay OFF
  delay(2000);
}
