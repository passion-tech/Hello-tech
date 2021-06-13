#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16,2);//Make sure you put your I2C lcd code.

#define Sensor A0
float vOUT =0.0;
float vIN=0.0;
float R1=30000.0;//30kohms resistor
float R2=7500.0;//7.5kohms resistor

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  // put your setup code here, to run once:

}

void loop() {
  int value=analogRead (Sensor);
  vOUT=(value *5.0) / 1024.0;
  vIN=vOUT / (R2/(R1 + R2));

Serial.print("Voltage:");
Serial.print(vIN);

  lcd.setCursor (0,0);
  lcd.print("Voltage;");
  lcd.print(vIN);
  lcd.print("v");
  // put your main code here, to run repeatedly:

}
