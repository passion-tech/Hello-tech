#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int irSensor = 8; // IR sensor connected to pin 8
int objectCount = 0;
int sensorState = 0;
int lastSensorState = 0;

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Object Count:");

  // Initialize the IR sensor pin as input
  pinMode(irSensor, INPUT);
}

void loop() {
  // Read the state of the IR sensor
  sensorState = digitalRead(irSensor);

  // Check if the IR sensor state has changed from low to high
  if (sensorState == HIGH && lastSensorState == LOW) {
    objectCount++;
    lcd.setCursor(0, 1); // Move the cursor to the second row
    lcd.print("Count: ");
    lcd.print(objectCount);
  }

  // Save the current state as the last state
  lastSensorState = sensorState;

  delay(100); // Small delay to debounce the sensor
}
