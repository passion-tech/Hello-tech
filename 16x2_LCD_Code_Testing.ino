#include <LiquidCrystal.h>

// Initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello, World!");
}

void loop() {
  // Set the cursor to column 0, line 1 (second row)
  lcd.setCursor(0, 1);
  // Print the number of seconds since reset:
  lcd.print(millis() / 1000);
}