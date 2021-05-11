#include <LiquidCrystal_I2C.h>//This file is require to download
LiquidCrystal_I2C lcd(0x27,16,2);// To know i2c number you just simply run i2c scanner code.
#include <DS1302.h>// This file is require to download.
DS1302 rtc(3, 2, 1); //RST to D3,DAT to D2,CLK to D1 Pins of the DS1302 Module 


void setup()
{
  rtc.halt(false);
  rtc.writeProtect(false);
  lcd.backlight();
  lcd.init();
  lcd.begin(16, 2);
  //comment this section later ,first upload no comment its for RTC ,secod time upload set comment for Arduino
 //rtc.setDOW(THURSDAY);      //name of the day of the week Follow your current day
 //rtc.setTime(10, 02, 00);  //Hour, Min, Sec Follow your current time
 //rtc.setDate(06, 05, 2021); //Day, Month, Year follow your current year
}

void loop()
{
  lcd.setCursor(0,1);
  lcd.print("Time:");
  lcd.setCursor(5, 1);
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(0, 0);
  lcd.print("Date:");
  lcd.setCursor(5,0);
  lcd.print(rtc.getDateStr(FORMAT_SHORT, FORMAT_LITTLEENDIAN, '/'));
  //lcd.setCursor(13,1);
  //lcd.print(rtc.getDOWStr());
  delay (1000); 
}
