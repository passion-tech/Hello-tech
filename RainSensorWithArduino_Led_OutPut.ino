// Define pins
const int rainSensorPin = A0;  // Analog pin connected to raindrop sensor output
const int ledPin = 9;         // Digital pin connected to LED

// Threshold value for detecting rain
const int rainThreshold = 500; // Adjust based on your sensor's sensitivity

void setup() {
  pinMode(ledPin, OUTPUT);    // Set LED pin as output
  pinMode(rainSensorPin, INPUT); // Set rain sensor pin as input
  Serial.begin(9600);         // Initialize serial communication for debugging
}

void loop() {
  // Read the analog value from the rain sensor
  int sensorValue = analogRead(rainSensorPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Check if the sensor value exceeds the threshold
  if (sensorValue < rainThreshold) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }

  delay(500); // Small delay for stability
}
