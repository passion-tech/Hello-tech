// Pin connected to the LED
int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn LED on
  delay(500);                // Wait 1 second
  digitalWrite(ledPin, LOW);  // Turn LED off
  delay(500);                // Wait 1 second
}
