#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Define relay pins
int relay1 = 25;
int relay2 = 26;
int relay3 = 27;
int relay4 = 14;

void setup() {
  // Start Bluetooth
  Serial.begin(115200);
  SerialBT.begin("ESP32_Relay"); // Bluetooth name

  // Set relay pins as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  // All relays OFF at start (for active LOW modules use HIGH)
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);

  Serial.println("Bluetooth device is ready to pair");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read();  // Read incoming character

    switch (command) {
      case '1': digitalWrite(relay1, LOW); SerialBT.println("Relay 1 ON"); break;
      case '2': digitalWrite(relay2, LOW); SerialBT.println("Relay 2 ON"); break;
      case '3': digitalWrite(relay3, LOW); SerialBT.println("Relay 3 ON"); break;
      case '4': digitalWrite(relay4, LOW); SerialBT.println("Relay 4 ON"); break;

      case 'A': digitalWrite(relay1, HIGH); SerialBT.println("Relay 1 OFF"); break;
      case 'B': digitalWrite(relay2, HIGH); SerialBT.println("Relay 2 OFF"); break;
      case 'C': digitalWrite(relay3, HIGH); SerialBT.println("Relay 3 OFF"); break;
      case 'D': digitalWrite(relay4, HIGH); SerialBT.println("Relay 4 OFF"); break;

      case 'X': // All relays ON
        digitalWrite(relay1, LOW);
        digitalWrite(relay2, LOW);
        digitalWrite(relay3, LOW);
        digitalWrite(relay4, LOW);
        SerialBT.println("All Relays ON");
        break;

      case 'Y': // All relays OFF
        digitalWrite(relay1, HIGH);
        digitalWrite(relay2, HIGH);
        digitalWrite(relay3, HIGH);
        digitalWrite(relay4, HIGH);
        SerialBT.println("All Relays OFF");
        break;
    }
  }
}
