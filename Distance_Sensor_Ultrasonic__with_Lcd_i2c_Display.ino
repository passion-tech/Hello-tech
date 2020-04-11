#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <TimerOne.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trigger 7
#define echo 6
 
float time=0,distance=0;
 
void setup()
{
  Wire.begin();
 lcd.begin(16,2);
 lcd.backlight();
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 lcd.print(" Ultra sonic");
 lcd.setCursor(0,1);
 lcd.print("Distance Meter");
 delay(2000);
 lcd.clear();
 lcd.print(" Circuit Digest");
 delay(2000);
 lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Distance:");
 lcd.setCursor(0,1);
 lcd.print("Distance:");
}
 
void loop()
{
 //lcd.clear();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 //lcd.clear();
 //lcd.print("Distance:");
  lcd.setCursor(10,0);
 lcd.print(distance);
 lcd.print("CM");
 lcd.setCursor(10,1);

 //lcd.print("Distance:");
 lcd.print(distance/100);
 lcd.print(" M");
 delay(1000);
}
