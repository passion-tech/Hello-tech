#include <HX711_ADC.h> // need to install 
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // need to install

HX711_ADC LoadCell(6, 7); // parameters: dt pin 6, sck pin 7;
LiquidCrystal_I2C lcd(0x27, 16,2); // 0x27 is the i2c address might different;you can check with Scanner

void setup() 
{
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(2000); // load cells gets 2000ms of time to stabilize
  LoadCell.setCalFactor(1000.0); // calibration factor for load cell => dependent on your individual setup
  lcd.init(); 
  lcd.backlight();
}

void loop() {
  LoadCell.update(); // retrieves data from the load cell
  float i = LoadCell.getData(); // get output value
  lcd.setCursor(0, 0); // set cursor to first row
  lcd.print("Weight[g]:"); // print out to LCD
  lcd.setCursor(0, 1); // set cursor to second row
  lcd.print(i); // print out the retrieved value to the second row
}
