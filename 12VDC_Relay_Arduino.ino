const int relayPin = 8;  // Pin connected to the relay

void setup() {
  pinMode(relayPin, OUTPUT);  // Set relay pin as output
}

void loop() {
  digitalWrite(relayPin, LOW); // Turn relay ON
  delay(5000);                  // Wait 5 seconds
  digitalWrite(relayPin, HIGH);  // Turn relay OFF
  delay(5000);                  // Wait 5 seconds
}
