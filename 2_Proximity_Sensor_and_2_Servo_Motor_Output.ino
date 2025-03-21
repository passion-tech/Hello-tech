#include <Servo.h>

// Define sensor pins
const int sensor1Pin = 2;
const int sensor2Pin = 3;

// Define servo objects
Servo servo1;
Servo servo2;

// Define servo control pins
const int servo1Pin = 9;
const int servo2Pin = 10;

void setup() {
    // Set sensor pins as input
    pinMode(sensor1Pin, INPUT);
    pinMode(sensor2Pin, INPUT);
    
    // Attach servos to pins
    servo1.attach(servo1Pin);
    servo2.attach(servo2Pin);

    // Set servos to default position
    servo1.write(0);
    servo2.write(0);
}

void loop() {
    // Read sensor states
    int sensor1State = digitalRead(sensor1Pin);
    int sensor2State = digitalRead(sensor2Pin);

    // Control Servo 1
    if (sensor1State == HIGH) {
        servo1.write(90); // Move to 90° if sensor 1 is triggered
    } else {
        servo1.write(0);  // Default position
    }

    // Control Servo 2
    if (sensor2State == HIGH) {
        servo2.write(90); // Move to 90° if sensor 2 is triggered
    } else {
        servo2.write(0);  // Default position
    }

    delay(100); // Small delay to stabilize readings
}
