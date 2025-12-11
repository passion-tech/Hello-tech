#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// ---------------- LCD ----------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- RELAY ----------------
#define RELAY_PIN 23
#define ACTIVE_LOW true   // change to false if your relay is active HIGH

// ---------------- PASSWORD ----------------
String password = "1234";
String input = "";

// ---------------- KEYPAD ----------------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {19, 18, 5, 15};
byte colPins[COLS] = {13, 12, 14, 27};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// ---------------- FUNCTIONS ----------------
void relayOn() {
  digitalWrite(RELAY_PIN, ACTIVE_LOW ? LOW : HIGH);
}

void relayOff() {
  digitalWrite(RELAY_PIN, ACTIVE_LOW ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);

  // Relay setup
  pinMode(RELAY_PIN, OUTPUT);
  relayOff();

  // LCD setup
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter Password");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '*') {
      input = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(500);
      lcd.clear();
      lcd.print("Enter Password");
    }
    else if (key == '#') {
      if (input == password) {
        lcd.clear();
        lcd.print("Access Granted");
        relayOn();
        delay(3000);
        relayOff();
        lcd.clear();
        lcd.print("Enter Password");
      } else {
        lcd.clear();
        lcd.print("Wrong Password");
        delay(1500);
        lcd.clear();
        lcd.print("Enter Password");
      }
      input = "";
    }
    else {
      if (input.length() < 8)
        input += key;

      lcd.setCursor(0,1);
      for (int i=0; i<input.length(); i++)
        lcd.print("*");
    }
  }
}
