const int inPin =A0;
const int iteration = 1000; 
const float LM35_FACTOR =0.01;// do not change


#include <LiquidCrystal_I2C.h>  // Declear the I2C LCD library file.

LiquidCrystal_I2C lcd(0x27, 16, 2);// Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("LM35 with LCD for Arduino");
    
  lcd.init();// if your code is error on this you can try with lcd.begin();  
  lcd.backlight();
  lcd.print("LM35");
  lcd.setCursor(0,1);
  lcd.print("Temp: "); 
}


void loop() {
  
  lcdDisplay(getTemperature('C'),'C');
  delay(5000);
  
  lcdDisplay(getTemperature('F'),'F');
  delay(5000);
    
  lcdDisplay(getTemperature('K'),'K');  
  delay(5000);    

}

float getTemperature(char type)
{
    float value;
    float averageTemperature =0;
    int sensorValue = analogRead(inPin);
    float voltage = sensorValue * (5.0 / 1023.0); 
    float temperature = voltage / LM35_FACTOR;
    for(int i=0; i< iteration; i++)
    {
      averageTemperature += temperature;
    }

    averageTemperature /=iteration;
  if(type =='F')
   {
    value = averageTemperature *9/5 + 32;//convert to Fahrenheit 
   }else if(type =='K')
   {
    value = averageTemperature + 273.15;//convert to Kelvin
   }else{
    value = averageTemperature;// return Celsius
   }    
    return value ;
}


void printTemperature(char type)
{
    float value;
    float temp = getTemperature(type);
   Serial.print(temp);
    printDegree();    
  if(type =='F')
   {
     Serial.print("F");
    }else if(type =='K')
   {
     Serial.print("K");
   }else{
     Serial.print("C");
   }    
 
}
void printDegree()
{
    Serial.print("\xC2"); 
    Serial.print("\xB0");  
}


void lcdDisplay(float value,char symbol)
{
     

   for(int i=7; i<16;i++)
   {
    lcd.setCursor(i,1);
    lcd.write(254);  
   }
   lcd.setCursor (7,1); //
   lcd.print(value);
   lcd.print((char)223);    
   if(symbol =='F')
   {
    lcd.print("F");
   }else if(symbol =='K')
   {
    lcd.print("K");
   }else{
    lcd.print("C");    
   }
}  
