const int relay =2; // D2 pin for output 
void setup() {
  Serial.begin(9600);
  pinMode(relay,OUTPUT);

}

void loop() {
  if(Serial.available()>0)
  {
    char data = Serial.read();
    if (data == 'a')
    {
      digitalWrite(relay,HIGH);
    }
    else if(data == 'b')
    {
      digitalWrite(relay,LOW);
    }
  }


}
