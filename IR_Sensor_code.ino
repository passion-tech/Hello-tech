#define Sensor pin=7;//Ir sensor pin
#define Action pin=13;//Led Or Relay

void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(7,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(7)==HIGH)
{
  digitalWrite(13,LOW);
  delay(100);
  
}
else
{digitalWrite(13,HIGH);
delay(10);
}


}
