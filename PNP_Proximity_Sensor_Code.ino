const int sensorPin = 2;     // Connected to PNP sensor output (black wire)
const int RelayPin = 13;       

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(RelayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(sensorPin);

  if (sensorState == HIGH) {
    Serial.println("Object Detected");
    digitalWrite(RelayPin, HIGH); 
  } else {
    Serial.println("No Object");
    digitalWrite(RelayPin, LOW);  
  }

  delay(200);
}
