#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

// Pin definitions
const int sensorPin = 2;  // DS18B20 data pin
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;  // LCD pinout

// Setup the OneWire and DallasTemperature libraries
OneWire oneWire(sensorPin);
DallasTemperature sensors(&oneWire);

// Setup the LCD display
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Start the DallasTemperature library
  sensors.begin();
  
  // Initialize the LCD display
  lcd.begin(16, 2);
  
  // Print a welcome message to the LCD display
  lcd.print("Temperature: ");
}

void loop() {
  // Request temperature readings from the DS18B20 sensor
  sensors.requestTemperatures();

  // Read the temperature and convert it to Celsius
  float tempC = sensors.getTempCByIndex(0);

  // Print the temperature to the serial monitor for debugging
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

  // Display the temperature on the LCD display
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.print(" C");
  
  // Wait for 1 second before repeating
  delay(1000);
}
