void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  // put your setup code here, to run once:

}

void loop() 
{
  digitalWrite(9,HIGH);//on red
  digitalWrite(11,LOW);//off blue
  delay(1000);

 digitalWrite(10,HIGH);//on green
 digitalWrite(9,LOW);//off red
 delay(1000);

 digitalWrite(11,HIGH);//on blue
 digitalWrite(10,LOW); //off green
 delay(1000);
  // put your main code here,to run repeatedly:

}
