#define RELAY1 2
#define RELAY2 3

void setup() {
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  // Relay OFF at start (most relay modules are LOW active)
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
}

void loop() {
  // Relay 1 ON
  digitalWrite(RELAY1, LOW);
  delay(2000);

  // Relay 2 ON
  digitalWrite(RELAY2, LOW);
  delay(2000);

  // Relay 1 OFF
  digitalWrite(RELAY1, HIGH);
  delay(2000);

  // Relay 2 OFF
  digitalWrite(RELAY2, HIGH);
  delay(2000);
}
