int touchPin = 2;
int relayPin = 3;

int val = 0;
int lightON = 0;
int touched = 0;

void setup() {
  Serial.begin(9600);
  pinMode(touchPin, INPUT); 
  pinMode(relayPin, OUTPUT);

}

void loop() {

  val = digitalRead(touchPin);

  if(val == HIGH && lightON == LOW){

    touched = 1-touched;
    delay(100);
  }    

  lightON = val;

      if(touched == HIGH){
        Serial.println("Light ON");
        digitalWrite(relayPin, LOW); 
       
      }else{
        Serial.println("Light OFF");
        digitalWrite(relayPin, HIGH);
   
      }     

  delay(100);
}
