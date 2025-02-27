#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Define I2C LCD (16x2, Address 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define Pins
#define PROXIMITY_SENSOR_PIN 2  // Inductive Sensor Input
#define SERVO_PIN 8             // Servo Motor Output

Servo servoMotor;
int objectCount = 0;
bool lastState = LOW;

void setup() {
    pinMode(PROXIMITY_SENSOR_PIN, INPUT);
    servoMotor.attach(SERVO_PIN);
    servoMotor.write(0); // Initial position
    
    // Initialize LCD
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Objects: 0");
}

void loop() {
    bool currentState = digitalRead(PROXIMITY_SENSOR_PIN);
    
    if (currentState == HIGH && lastState == LOW) { // Detect rising edge
        objectCount++;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Objects: ");
        lcd.print(objectCount);
        delay(300); // Debounce
    }
    
    lastState = currentState;
    
    if (objectCount >= 3) {
        servoMotor.write(90); // Move servo when 3 objects detected
        lcd.setCursor(0, 1);
        lcd.print("Servo Activated");
        delay(2000);
        objectCount = 0; // Reset count after activation
        servoMotor.write(0); // Reset servo
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Objects: 0");
    }
}
