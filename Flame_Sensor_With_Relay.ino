#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define your sensor and LCD
int flameSensorPin = A0;
int relayPin = 8;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27 for the 2x16 LCD

void setup() {
  // Initialize LCD and relay pin
  lcd.init();
  lcd.backlight();
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Turn off the relay initially
}

void loop() {
  // Read flame sensor
  int flameValue = analogRead(flameSensorPin);

  // Display on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Flame Sensor:");
  lcd.setCursor(0, 1);
  lcd.print(flameValue);

  delay(2000); // Wait for a moment to read the display

  // Check flame sensor and control the relay
  if (flameValue > 500) {
    // Flame is detected, turn on the relay
    digitalWrite(relayPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No Flame Detected");
    lcd.setCursor(0, 1);
    lcd.print("Relay: OFF");
  } else {
    // No flame detected, turn off the relay
    digitalWrite(relayPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Flame Detected");
    lcd.setCursor(0, 1);
    lcd.print("Relay: ON");
  }

  delay(2000); // Update every 2 seconds
}