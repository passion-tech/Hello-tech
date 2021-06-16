// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); //The LCD address and size. You can change according you yours
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2 //pin for sensor
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
/*
   The setup function. We only start the sensors here
*/
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors.begin();
  lcd.init();//initialize the lcd
  lcd.backlight();//Open the back lignt
}
/*
   Main function, get and show the temperature
*/
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);
  // Check if reading was successful
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("DS18B20 Temperature");
    Serial.println(tempC);
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor(0, 1);
    lcd.print(tempC);
    lcd.print((char)223);
    lcd.print("C");
    lcd.print("|");
    lcd.print(DallasTemperature::toFahrenheit(tempC));
    lcd.print("F");
  }
  else
  {
    Serial.println("Error: Could not read temperature data");
    lcd.setCursor(0, 0);
    lcd.println("      Sorry!!     ");
    lcd.setCursor(0, 1);
    lcd.println("    Data Error     ");
  }
}
