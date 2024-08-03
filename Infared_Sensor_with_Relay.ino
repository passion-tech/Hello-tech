const int irSensorPin = 2; // IR sensor connected to digital pin 2
const int ledPin = 13;     // LED connected to digital pin 13

void setup() {
  pinMode(irSensorPin, INPUT); // Set the IR sensor pin as input
  pinMode(ledPin, OUTPUT);     // Set the LED pin as output
  Serial.begin(9600);          // Initialize serial communication at 9600 baud
}

void loop() {
  int sensorValue = digitalRead(irSensorPin); // Read the value from the IR sensor

  if (sensorValue == LOW) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Object detected!");
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.println("No object detected.");
  }

  delay(100); // Wait for 100 milliseconds
}