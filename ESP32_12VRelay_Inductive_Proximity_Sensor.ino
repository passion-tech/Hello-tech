#define SENSOR_PIN 27  // Input from proximity sensor 
#define RELAY_PIN 26   // Relay input pin (active LOW)

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);  // Sensor output: LOW = metal detected
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);      // Keep relay OFF initially
  Serial.begin(115200);
  Serial.println("ESP32 + NPN sensor + active-LOW relay ready");
}

void loop() {
  int sensorState = digitalRead(SENSOR_PIN);

  if (sensorState == LOW) {
    // Metal detected → turn relay ON (LOW signal)
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Metal detected → Relay ON");
  } else {
    // No metal → turn relay OFF (HIGH signal)
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("No metal → Relay OFF");
  }

  delay(100);
}


