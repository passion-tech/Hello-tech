const int trigPin = 8;

const int echoPin = 9;

long duration;
int distance;

void setup() {
pinMode (2,OUTPUT);
pinMode (trigPin,OUTPUT);
pinMode (echoPin,INPUT);
Serial.begin(9600);
}
void loop() {

digitalWrite(trigPin,LOW);
delayMicroseconds (2);

digitalWrite(trigPin,HIGH);
delayMicroseconds (10);
digitalWrite(trigPin,LOW);

duration = pulseIn(echoPin,HIGH);
digitalWrite(trigPin,HIGH);

distance = duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

if (distance <=10)
{
digitalWrite(2,LOW);
delay(500);
}
else
{
digitalWrite(2,HIGH);
delay(500);
}
}
