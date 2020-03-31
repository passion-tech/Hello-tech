

const int SENSOR_PIN = 2;
const int RELAY_PIN = 4;

void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
   Serial.println("Arduino Tutorial");
   Serial.println("HC-SR501 sensor with relay");
  pinMode(SENSOR_PIN, INPUT);// Define SENSOR_PIN as Input from sensor
  pinMode(RELAY_PIN, OUTPUT);// Define RELAY_PIN as OUTPUT for relay
}

void loop() {
  int motion =digitalRead(SENSOR_PIN);
 
  // if motion is detected
  if(motion){
    Serial.println("Motion detected");
    digitalWrite(RELAY_PIN, LOW);// Turn the relay ON
  }else{
     Serial.println("===nothing moves");
     digitalWrite(RELAY_PIN,HIGH);// Turn the relay OFF
  }
  delay(500);
}

 
