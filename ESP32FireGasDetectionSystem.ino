#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// DHT settings
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Sensor pins
#define GAS_SENSOR 34
#define FLAME_SENSOR 35
#define BUZZER 25   // 🔔 Buzzer pin

// Threshold
#define GAS_THRESHOLD 600   // adjust based on testing

void setup() {
  Serial.begin(115200);

  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while (true);
  }

  pinMode(FLAME_SENSOR, INPUT);
  pinMode(BUZZER, OUTPUT);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  int gasValue = analogRead(GAS_SENSOR);
  int flame = digitalRead(FLAME_SENSOR);

  bool gasDetected = gasValue > GAS_THRESHOLD;
  bool flameDetected = (flame == LOW); // change if needed

  // 🔔 Buzzer Logic
  if (gasDetected || flameDetected) {
    digitalWrite(BUZZER, HIGH);  // ON
  } else {
    digitalWrite(BUZZER, LOW);   // OFF
  }

  // Serial Monitor
  Serial.print("Temp: "); Serial.print(temp);
  Serial.print("  Hum: "); Serial.print(hum);
  Serial.print("  Gas: "); Serial.print(gasValue);
  Serial.print("  Flame: "); Serial.println(flame);

  // OLED Display
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print("Temp: "); display.print(temp); display.println(" C");

  display.setCursor(0, 10);
  display.print("Hum: "); display.print(hum); display.println(" %");

  display.setCursor(0, 20);
  display.print("Gas: "); display.println(gasValue);

  display.setCursor(0, 30);
  display.print("Flame: ");
  display.println(flameDetected ? "DETECTED!" : "Safe");

  display.setCursor(0, 45);
  if (gasDetected || flameDetected) {
    display.println("⚠ ALERT!");
  } else {
    display.println("System Normal");
  }

  display.display();

  delay(2000);
}