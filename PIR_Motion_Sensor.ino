void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(8, INPUT);// Input from sensor
  pinMode(9, OUTPUT);// OUTPUT to relay
}

void loop() {
  int motion =digitalRead(8);
  if(motion){
    Serial.println("Motion detected");
    digitalWrite(9,LOW);
  }else{
     Serial.println("===nothing moves");
     digitalWrite(9,HIGH);
  }
  delay(10);

}
