#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // to check your i2c address  upload i2c scanner to the board.

void setup()
{
  lcd.init();//if you can not upload this code lcd.init(); and change to lcd.begin(); 
  lcd.backlight();

}

void loop()
{
 
  lcd.clear();
  lcd.print("Welcom to ");
  lcd.setCursor (0,1); // go to start of 2nd line
 lcd.print("Passion Tech MMR");
  //lcd.print(millis() / 1000);
  delay(500);
 //end of loopcode 
}
