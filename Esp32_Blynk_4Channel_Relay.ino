#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials
char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

// Relay pins (adjust if using other GPIOs)
#define RELAY1  26
#define RELAY2  27
#define RELAY3  14
#define RELAY4  12

// Blynk virtual pins
#define VPIN1   V1
#define VPIN2   V2
#define VPIN3   V3
#define VPIN4   V4

BLYNK_WRITE(VPIN1) {
  int value = param.asInt();
  digitalWrite(RELAY1, value);
}

BLYNK_WRITE(VPIN2) {
  int value = param.asInt();
  digitalWrite(RELAY2, value);
}

BLYNK_WRITE(VPIN3) {
  int value = param.asInt();
  digitalWrite(RELAY3, value);
}

BLYNK_WRITE(VPIN4) {
  int value = param.asInt();
  digitalWrite(RELAY4, value);
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  // Start with all relays OFF
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);
  digitalWrite(RELAY4, HIGH);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
}
