#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RELAY_PIN 2  // Replace with the actual pin you connect the relay to
#define GAS_SENSOR_PIN A0  // Replace with the actual pin you connect the gas sensor to

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C address 0x27, 16 columns and 2 rows

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Gas Detector");
  delay(2000);
  lcd.clear();
}

void loop() {
  int gasValue = analogRead(GAS_SENSOR_PIN);

  if (gasValue > 250) {  // Adjust the threshold based on your sensor's characteristics
    lcd.setCursor(0, 0);
    lcd.print("Gas detected!");
    digitalWrite(RELAY_PIN, LOW);  // Turn on the relay
  } else {
    lcd.setCursor(0, 0);
    lcd.print("No gas detected");
    digitalWrite(RELAY_PIN, HIGH);  // Turn off the relay
  }

  lcd.setCursor(0, 1);
  lcd.print("Gas Value: ");
  lcd.print(gasValue);

  delay(3000);  // Adjust the delay based on your needs
}