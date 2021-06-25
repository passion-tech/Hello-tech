// include the library code: 
//#include <LiquidCrystal.h>
//initialise the library with the numbers of the interface pins 
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
 
int resval = 0;  // holds the value
int respin = A0; // sensor pin used
  
void setup() { 
 
  // Lcd initialize 
  lcd.init();
  lcd.backlight(); 
  
  // Print a message to the LCD. 
  lcd.print("WATER LEVEL"); 
  delay(3000);
} 
  
void loop() { 
  // set the cursor to column 0, line 1 
  lcd.clear();
  lcd.setCursor(0, 1); 
    
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval<=100){ lcd.println("Empty            ");
  } 
  else if (resval>100 && resval<=300)
  { 
    lcd.println("Low             ");
  } 
  
  else if (resval>300 && resval<=330)
  { 
    lcd.println("Medium           ");
    
  } 
  
  else if (resval>330){ 
    lcd.println("High            "); 
  }
  delay(1000); 
}
