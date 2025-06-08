#include <VARSTEP_ultrasonic.h> // Include the custom VARSTEP_ultrasonic library to control the ultrasonic sensor

#define trigger_pin 8            // Define the pin connected to the ultrasonic sensor's trigger pin
#define echo_pin 9               // Define the pin connected to the ultrasonic sensor's echo pin
#define motor_pin 10             // Define the pin connected to the DC motor driver

double distance_cm, distance_m;  // Declare variables to store the measured distance in centimeters and meters
int pwm_value;                   // Declare a variable to store the PWM value used to control motor speed

VARSTEP_ultrasonic my_HCSR04(trigger_pin, echo_pin); // Create an instance of the ultrasonic sensor with the specified trigger and echo pins

void setup() {
  Serial.begin(9600);            // Initialize serial communication at 9600 baud rate for debugging
  pinMode(motor_pin, OUTPUT);    // Set the motor pin as an output
}

void loop() {
  distance_cm = my_HCSR04.distance_cm(); // Measure the distance in centimeters using the ultrasonic sensor
  distance_m = my_HCSR04.distance_m();   // Measure the distance in meters using the ultrasonic sensor

  if (distance_cm == -1.0 || distance_cm > 10) { // Check if no distance is detected or if the distance is greater than 10 cm
    Serial.println("No distance detected");      // Print a message if no distance is detected
    analogWrite(motor_pin, 0);                   // Stop the motor if no distance is detected
  } else {
    Serial.print("Distance: ");                  // Print the detected distance
    Serial.print(distance_cm);                   // Print the distance in centimeters
    Serial.print("cm | ");
    Serial.print(distance_m);                    // Print the distance in meters
    Serial.println("m");

    // Map the distance to a PWM value to control motor speed
    pwm_value = map(distance_cm, 10, 2, 0, 255); // Map the distance range (10 cm to 2 cm) to a PWM range (0 to 255)
    pwm_value = constrain(pwm_value, 0, 255);    // Ensure the PWM value stays within the 0-255 range

    analogWrite(motor_pin, pwm_value);           // Control the motor speed based on the distance
  }

  delay(100); // Short delay of 100 ms for good accuracy in distance measurement and motor control
}
