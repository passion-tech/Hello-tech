#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// Initialize the MPU6050
MPU6050 mpu;

// Initialize the servo motor
Servo myServo;

// Initialize the I2C LCD (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Start the I2C communication
  Wire.begin();

  // Initialize the LCD and print a message
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  // Initialize the MPU6050
  mpu.initialize();
  if (mpu.testConnection()) {
    lcd.setCursor(0, 1);
    lcd.print("MPU6050 OK");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("MPU6050 Fail");
    while (1); // Halt if MPU6050 fails
  }

  // Attach the servo motor to pin 9
  myServo.attach(9);
  myServo.write(90); // Start with the servo at 90 degrees

  // Clear the initialization message after setup
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read raw values from the MPU6050
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Convert accelerometer readings to angles (simplified for demonstration)
  float angleX = ax / 16384.0 * 90;
  float angleY = ay / 16384.0 * 90;

  // Map the X angle to servo range (0-180 degrees)
  int servoAngle = map(angleX, -90, 90, 0, 180);
  myServo.write(servoAngle);

  // Display the data on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Servo: ");
  lcd.print(servoAngle);

  lcd.setCursor(0, 1);
  lcd.print("AngleX: ");
  lcd.print(angleX);

  delay(100);
}
