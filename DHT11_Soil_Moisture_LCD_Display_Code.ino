#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2        // Pin which is connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define SOIL_MOISTURE_PIN A0  // Pin which is connected to the soil moisture sensor

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Initialize the library with the interface pins

void setup() {
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows
  dht.begin();
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // Read humidity and temperature
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Read soil moisture
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  // Print to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h);
  lcd.print(" %");
  
  delay(2000); // Wait a few seconds between measurements

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
  lcd.setCursor(0, 1);
  lcd.print(soilMoistureValue);

  delay(2000); // Wait a few seconds between measurements
}