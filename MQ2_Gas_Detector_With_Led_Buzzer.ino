#define MQ2_A0 A0  // Analog pin for MQ2 sensor
#define LED 8      // LED output pin
#define BUZZER 9   // Buzzer output pin
#define GAS_THRESHOLD 50  // Adjust threshold based on testing

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(MQ2_A0, INPUT);
    Serial.begin(9600);
}

void loop() {
    int gasValue = analogRead(MQ2_A0);
    Serial.print("Gas Level: ");
    Serial.println(gasValue);

    if (gasValue > GAS_THRESHOLD) { 
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
    } else {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
    }

    delay(3000); // Read every 1000ms
}
