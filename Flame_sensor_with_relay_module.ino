#define Sensor 7 // connect digital output(DO) pin of sensor to this pin
#define Relay 8 // pin 8 for Alarm 


void setup() {
  Serial.begin(9600);
  Serial.println("Flame Sensor Testing");
  pinMode(Sensor  , INPUT);
  pinMode(Relay , OUTPUT);

}

void loop() {

  int fire = digitalRead(Sensor);// read FLAME sensor


  if( fire == HIGH)
  {
    digitalWrite(Relay ,HIGH);// set the buzzer ON
    Serial.println("Fire! Fire! Fire!");
  }else{
    digitalWrite(Relay ,LOW); // Set the buzzer OFF
    Serial.println("Clear");

  }



  delay(200);
}       
