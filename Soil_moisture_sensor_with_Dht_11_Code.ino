#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

// Define your sensor and LCD
#define DHTPIN 2 // DHT11 data pin
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27 for the 2x16 LCD

// Soil moisture sensor
int soilMoisturePin = A0;
int soilMoistureThreshold = 700; // Adjust this threshold as needed
int relayPin = 8;

void setup() {
  // Initialize sensors and LCD
  dht.begin();
  lcd.init();
  lcd.backlight();

  // Relay pin setup
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Turn off the relay initially
}

void loop() {
  // Read soil moisture
  int soilMoisture = analogRead(soilMoisturePin);

  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Display on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
  lcd.setCursor(0, 1);
  lcd.print(soilMoisture);

  delay(2000); // Wait for a moment to read the display

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  // Check soil moisture level and control the relay
  if (soilMoisture < soilMoistureThreshold) {
    // Soil is too dry, turn on the relay
    digitalWrite(relayPin, HIGH);
  } else {
    // Soil is wet enough, turn off the relay
    digitalWrite(relayPin, LOW);
  }

  delay(2000); // Update every 2 seconds
}
