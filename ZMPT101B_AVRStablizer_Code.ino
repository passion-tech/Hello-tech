#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Use 0x3F if needed

const int sensorPin = A0;
const int relayPin = 8;
const int buzzerPin = 13;

float calibrationFactor = 194.0;  // ✅ Adjust for accurate reading

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(relayPin, LOW);
  digitalWrite(buzzerPin, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ZMPT101B Sensor");
  delay(2000);
  lcd.clear();
}

void loop() {
  long sum = 0;
  int samples = 500;

  for (int i = 0; i < samples; i++) {
    int raw = analogRead(sensorPin);
    int centered = raw - 512;
    sum += (long)centered * centered;
    delayMicroseconds(200);
  }

  float mean = sum / (float)samples;
  float rms = sqrt(mean);
  float sensorVoltage = (rms * 5.0) / 1024.0;
  float acVoltage = sensorVoltage * calibrationFactor;

  // Display voltage
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");
  lcd.print(acVoltage, 1);
  lcd.print(" V   ");

  // Voltage status and actions
  if (acVoltage > 230.0) {
    digitalWrite(relayPin, HIGH);      // Relay OFF
    digitalWrite(buzzerPin, HIGH);    // Buzzer ON
    lcd.setCursor(0, 1);
    lcd.print("Over Voltage!   ");
  } 
  else if (acVoltage < 210.0) {
    digitalWrite(relayPin, HIGH);      // Relay OFF
    digitalWrite(buzzerPin, HIGH);    // Buzzer ON
    lcd.setCursor(0, 1);
    lcd.print("Low Voltage!    ");
  } 
  else {
    digitalWrite(relayPin,LOW);     // Relay ON
    digitalWrite(buzzerPin, LOW);     // Buzzer OFF
    lcd.setCursor(0, 1);
    lcd.print("Voltage OK      ");
  }

  // Serial monitor debug
  Serial.print("AC Voltage: ");
  Serial.println(acVoltage, 1);

  delay(1000);
}
