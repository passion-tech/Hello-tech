#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

#define ONE_WIRE_BUS 2 //Data wire is plug to D2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // rs=7,e=8,d4=9,d5=10,d6=11,d7=12.

// Define the pin for the relay module
int relayPin = 13;

// Define the temperature threshold for turning the relay on/off
float threshold = 32.0;

void setup() 
{
  // Start serial communication 
  Serial.begin(9600);
  
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  
  // Start up the temperature sensor library
  sensors.begin();
  
  // Set the relay pin as an output
  pinMode(relayPin, OUTPUT);
}

void loop() 
{
  // Call sensors.requestTemperatures() to issue a global temperature 
  sensors.requestTemperatures();
  
  // Get the temperature from the sensor and store it in a variable
  float temperatureC = sensors.getTempCByIndex(0);
  
  // Display the temperature on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C");
  
  // Print the temperature to the serial monitor for debugging purposes
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  // Check if the temperature is above the threshold
  if (temperatureC > threshold) {
    // Turn the relay on
    digitalWrite(relayPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Relay: ON ");
  } else {
    // Turn the relay off
    digitalWrite(relayPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Relay: OFF");
  }
  
  // Wait for 1 second before taking another reading
  delay(1000);
}
