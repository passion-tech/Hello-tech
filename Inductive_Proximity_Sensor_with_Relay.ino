#define SENSOR 7 // define pint 7 for sensor
#define ACTION 6 // define pin 6 as for ACTION


void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(SENSOR, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(ACTION, OUTPUT);// define pin as OUTPUT for ACTION
}

void loop() {
  int L =digitalRead(SENSOR);// read the sensor 
  
      if(L == 0){
    Serial.println(" All Clear");
    digitalWrite(ACTION,LOW);// send singal
    
     }else{

     Serial.println("  === Obstacle detacted");
     digitalWrite(ACTION,HIGH);// turn the relay ON
     }
  delay(100);
 
}
 
