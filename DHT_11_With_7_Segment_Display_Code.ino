// Include the libraries
#include <TM1637Display.h>// This file require to download
#include <Adafruit_Sensor.h>//This file require to download
#include <DHT.h>// This file require to download

// Define the connections pins
#define CLK 3
#define DIO 4
#define DHTPIN 5

// Create variable
int temperature_celsius;
int temperature_fahrenheit;

// Create °C symbol
const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_D | SEG_E | SEG_F   // C
};

// Create °F symbol
const uint8_t fahrenheit[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle
  SEG_A | SEG_E | SEG_F | SEG_G   // F
};

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)

// Create display object of type TM1637Display
TM1637Display display = TM1637Display(CLK, DIO);

// Create dht object of type DHT:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  // Set the display brightness (0-7)
  display.setBrightness(5);
  
  // Clear the display
  display.clear();
  
  // Setup sensor
  dht.begin();
}

void loop() {
  // Read the temperature as Celsius and Fahrenheit
  temperature_celsius = dht.readTemperature();
  temperature_fahrenheit = dht.readTemperature(true);

  // Display the temperature in celsius format
  display.showNumberDec(temperature_celsius, false, 2, 0);
  display.setSegments(celsius, 2, 2);
  delay(1000);

  // Display the temperature in fahrenheit format
  display.showNumberDec(temperature_fahrenheit, false, 2, 0);
  display.setSegments(fahrenheit, 2, 2);
  delay(1000);
}
