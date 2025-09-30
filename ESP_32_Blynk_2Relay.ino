#define BLYNK_TEMPLATE_ID "TMPL6EWC-oQzl"
#define BLYNK_TEMPLATE_NAME "ESP32 Home Automation 2 Relay"
#define BLYNK_AUTH_TOKEN "5mUnozWs8XXL7bZiP3dJvXnRe1-0A5EA"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Replace with your WiFi credentials
char ssid[] = "Myhome";
char pass[] = "01163962645";

// Relay pins
#define RELAY1_PIN 13
#define RELAY2_PIN 12

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Setup relay pins
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);

  // Set relays OFF initially
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Relay 1 control (V0)
BLYNK_WRITE(V1)
{
  int relayState = param.asInt();
  digitalWrite(RELAY1_PIN, relayState);
}

// Relay 2 control (V1)
BLYNK_WRITE(V2)
{
  int relayState = param.asInt();
  digitalWrite(RELAY2_PIN, relayState);
}

void loop()
{
  Blynk.run();
}
