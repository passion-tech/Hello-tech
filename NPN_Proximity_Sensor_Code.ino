 #include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Address (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const int sensorPin = 13;
const int relayPin  = 2;

void setup() {

  Serial.begin(9600);

  // NPN Sensor uses internal pull-up
  pinMode(sensorPin, INPUT_PULLUP);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Electronics");
  lcd.setCursor(0, 1);
  lcd.print("Lab");
  delay(2000);

  lcd.clear();
}

void loop() {

  // NPN sensor: LOW = Object Detected
  if (digitalRead(sensorPin) == LOW) {

    digitalWrite(relayPin, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("Object Detected");
    lcd.setCursor(0, 1);
    lcd.print("Relay : ON     ");

    Serial.println("Object Detected");

  }
  else {

    digitalWrite(relayPin, LOW);

    lcd.setCursor(0, 0);
    lcd.print("No Object      ");
    lcd.setCursor(0, 1);
    lcd.print("Relay : OFF    ");

    Serial.println("No Object");
  }

  delay(200);
}