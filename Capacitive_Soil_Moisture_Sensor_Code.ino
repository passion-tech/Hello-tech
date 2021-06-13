#include<LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd (0x27, 16,2);
#define sensor A2
#define wet 210
#define dry 510


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  // put your setup code here, to run once:

}

void loop() {
  int value=analogRead(sensor);
  Serial.println(value);
  lcd.setCursor(1,0);
  lcd.print("Moisture Value");
  lcd.setCursor(3,1);
  lcd.print(value);
  lcd.print(" ");
  lcd.setCursor(7,1);
  lcd.print("--");
  int pre = map (value,wet,dry,100,0);
  lcd.setCursor(10,1);
  lcd.print(pre);
  lcd.print("%");
  lcd.print(" ");
  // put your main code here, to run repeatedly:

}
