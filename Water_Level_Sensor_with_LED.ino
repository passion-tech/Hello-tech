const int analogInPin = A0;
int sensorValue = 0;

void setup() {
  // declare pin  to be an output:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(2);
  if((sensorValue>=100)&&(sensorValue<=600)){
    digitalWrite(2,HIGH);
    delay(100);
    }
  else if((sensorValue>=601)&&(sensorValue<=625)){
   digitalWrite(3,HIGH);
   delay(100);
    }  
  else if((sensorValue>=626)&&(sensorValue<=700)){
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    }
  else{
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    delay(100);
    }
}
