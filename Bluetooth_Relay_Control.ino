// Include required libraries
#include <SoftwareSerial.h>

// Define pins for Bluetooth module
#define BT_TX_PIN 10
#define BT_RX_PIN 11

// Define pin for relay module
#define RELAY_PIN 12

// Initialize software serial object for Bluetooth module
SoftwareSerial btSerial(BT_TX_PIN, BT_RX_PIN);

void setup() {
  // Set pin mode for relay
  pinMode(RELAY_PIN, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize software serial communication for Bluetooth module
  btSerial.begin(9600);

  // Wait for Bluetooth module to establish connection
  delay(1000);
  Serial.println("Bluetooth module ready.");
}

void loop() {
  // Check if there is any incoming data from Bluetooth module
  if (btSerial.available() > 0) {
    char incomingChar = btSerial.read();
    Serial.println(incomingChar);

    // If '1' is received, turn on the relay
    if (incomingChar == '1') {
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Relay turned on.");
    }

    // If '0' is received, turn off the relay
    if (incomingChar == '0') {
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("Relay turned off.");
    }
  }
}
