 //#include<Wire.h>
//#include <LiquidCrystal_I2C.h> // libray lcd
//LiquidCrystal_I2C lcd(0x27, 16, 2);


#include <LiquidCrystal.h>

int rs=12, en=11, d4=5, d5=4, d6=3, d7=2; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);



#include <DHT.h>  // library DHT11
DHT dht(7,DHT11); //Pin, types of  DHT model you use.

int relayPin=8;

int hum;
int temp;

void setup()
{
  dht.begin();
  lcd.begin(16,2);
  pinMode(relayPin,OUTPUT);
  
}
void loop()
{
  hum =dht.readHumidity();
  temp =dht.readTemperature();
  lcd.setCursor(0,0);
  lcd.print("Temperatur:");
  lcd.setCursor(12,0);
  lcd.print(temp);
  lcd.setCursor(14,0);
  lcd.print(".C");

  lcd.setCursor(0,1);
  lcd.print("Fan: ");
  lcd.setCursor(8,1);
  
  if(temp>32)
  {
  digitalWrite(relayPin,LOW); 
  lcd.print("FAN ON ");
  }
  else
  { 
  digitalWrite(relayPin,HIGH);
  lcd.print("FAN OFF");
  }
}
