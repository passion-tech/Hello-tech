#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHTPIN 7
#define DHTTYPE DHT11

#define RELAY_PIN 2
#define SOIL_PIN A0

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// Adjust this value after testing
int soilThreshold = 400;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // try HIGH if relay is active LOW

  Serial.begin(9600);
  dht.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soil = analogRead(SOIL_PIN);

  // Print values for debugging
  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" | Hum: "); Serial.print(hum);
  Serial.print(" | Soil: "); Serial.println(soil);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Display Temperature
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");

  // Display Humidity
  display.setCursor(0, 15);
  display.print("Hum: ");
  display.print(hum);
  display.println(" %");

  // Display Soil
  display.setCursor(0, 30);
  display.print("Soil: ");
  display.print(soil);

  display.setCursor(0, 50);

  // 🔥 SIMPLE RELAY LOGIC (ONLY SOIL)
  if (soil > soilThreshold) {
    digitalWrite(RELAY_PIN, HIGH);   // change to LOW if needed
    display.print("Relay: ON");
  } else {
    digitalWrite(RELAY_PIN, LOW);    // change to HIGH if needed
    display.print("Relay: OFF");
  }

  display.display();

  delay(2000);
}