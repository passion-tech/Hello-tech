#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// RTC Pins
#define CLK_PIN 18
#define DAT_PIN 19
#define RST_PIN 5

ThreeWire myWire(DAT_PIN, CLK_PIN, RST_PIN);
RtcDS1302<ThreeWire> rtc(myWire);

void setup() {
  Serial.begin(115200);

  Wire.begin(21, 22);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  rtc.Begin();

  rtc.SetIsWriteProtected(false);

  // 🔥 SMART CHECK
  if (!rtc.IsDateTimeValid()) {
    Serial.println("RTC lost time, setting again...");
    rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));
  }

  if (!rtc.GetIsRunning()) {
    Serial.println("RTC was stopped, starting...");
    rtc.SetIsRunning(true);
  }
}

void loop() {
  RtcDateTime now = rtc.GetDateTime();

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 10);
  display.printf("%02u:%02u:%02u",
                 now.Hour(),
                 now.Minute(),
                 now.Second());

  display.setTextSize(1);
  display.setCursor(25, 45);
  display.printf("%02u/%02u/%04u",
                 now.Day(),
                 now.Month(),
                 now.Year());

  display.display();

  delay(1000);
}