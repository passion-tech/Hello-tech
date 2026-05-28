#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// DS18B20
#define ONE_WIRE_BUS D4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Relay & Buzzer
#define RELAY_PIN D5
#define BUZZER_PIN D6

// Temperature Settings
float setTemp = 30.0;
float alarmTemp = 40.0;

void setup() {

  Serial.begin(115200);

  // Start temperature sensor
  sensors.begin();

  // Relay and buzzer
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // IMPORTANT:
  // Relay OFF at startup
  digitalWrite(RELAY_PIN, HIGH);

  digitalWrite(BUZZER_PIN, LOW);

 
 // OLED Start
  Wire.begin(D2, D1);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while(true);
  }

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);

  display.setCursor(10,20);
  display.println("TEMP CTRL");

  display.display();

  delay(2000);
}

void loop() {

  sensors.requestTemperatures();

  float tempC = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.println(tempC);

  // Relay Control
  // ACTIVE LOW relay
  if(tempC >= setTemp) {
    digitalWrite(RELAY_PIN, HIGH);   // ON
  }
  else {
    digitalWrite(RELAY_PIN, LOW);  // OFF
  }

  // Buzzer Alarm
  if(tempC >= alarmTemp) {
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // OLED Display
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Temperature");

  display.setTextSize(3);
  display.setCursor(10,20);
  display.print(tempC);
  display.print("C");

  display.setTextSize(1);
  display.setCursor(0,56);

  if(tempC >= setTemp) {
    display.println("Relay: ON");
  }
  else {
    display.println("Relay: OFF");
  }

  display.display();

  delay(1000);
}