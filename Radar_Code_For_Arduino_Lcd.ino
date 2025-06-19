#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define GREEN_LED 2
#define RED_LED 3
#define BUZZER 4
#define SERVO_PIN 6

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust if needed
Servo myServo;

int pos = 0;
int direction = 1;  // 1 = forward, -1 = backward

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  myServo.attach(SERVO_PIN);
  myServo.write(pos);
  
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" Sonar System ");
  delay(2000);
  lcd.clear();
}

long readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  long distance = readDistance();

  if (distance > 20 || distance == 0) {
    // No object detected
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    lcd.setCursor(0, 0);
    lcd.print(" Area is Empty ");
    lcd.setCursor(0, 1);
    lcd.print("                ");

    // Move servo faster (delay reduced)
    myServo.write(pos);
    delay(10);
    pos += direction;

    if (pos >= 180 || pos <= 0) {
      direction = -direction;
    }
  } else {
    // Object detected
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("   Warning      ");
    lcd.setCursor(0, 1);
    lcd.print(" Detect Something ");

    // Hold servo in place
    myServo.write(pos);
  }
}
