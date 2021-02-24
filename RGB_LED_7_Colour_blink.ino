const int red=9;
const int green=10;
const int blue=11;
int time=1000;
int multiple=2;

void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(red,HIGH); // red 
delay (time);

digitalWrite(green,HIGH);//yellow
delay(time);

digitalWrite(red,LOW);//green
delay(time);

digitalWrite(blue,HIGH);//cyan
delay(time);

digitalWrite(green,LOW);//blue
delay(time);

digitalWrite(red,HIGH);//megenta
delay(time);

digitalWrite(green,HIGH);//white
delay(time*=multiple);
digitalWrite(blue,LOW);//reset
digitalWrite(green,LOW);
delay(time/=multiple);

}
