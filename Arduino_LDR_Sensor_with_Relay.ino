
 #define LIGHT 2 // define pint 2 for sensor
#define RELAY 3 // define pin 3 as for relay


void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(LIGHT, INPUT_PULLUP);// sensor pin as input
  pinMode(RELAY, OUTPUT);// relay pin as output
}

void loop() {
    int LDR =digitalRead(LIGHT);// read the sensor 
  
      if(LDR == 1){
    Serial.println(" light is ON");
    digitalWrite(RELAY,LOW);// turn the relay ON
  }else{

     Serial.println("  === light is OFF");
     digitalWrite(RELAY,HIGH);// turn the relay OFF
  }
  delay(1000);
}
