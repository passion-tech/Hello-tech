void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
}
void loop()
{
  if (digitalRead(3)== LOW)
  {
    digitalWrite(2,LOW);
    
    delay(100);
  }
  else 
  {
    
    digitalWrite(2,HIGH);
    delay(10);
    
  }
  
}
