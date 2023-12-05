#define RAIN_SENSOR_PIN 2  // Replace with the actual pin you connect the raindrop sensor to
#define RELAY_PIN 3       // Replace with the actual pin you connect the relay to

void setup() {
  pinMode(RAIN_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int rainSensorValue = digitalRead(RAIN_SENSOR_PIN);

  if (rainSensorValue == HIGH) {
    Serial.println("Rain detected!");
    digitalWrite(RELAY_PIN, HIGH);  // Turn on the relay
  } else {
    Serial.println("No rain detected");
    digitalWrite(RELAY_PIN, LOW);   // Turn off the relay
  }

  delay(1000);  // Adjust the delay based on your needs
}