const int relay1 =8;
const int relay2 =9;
char val;


void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    val = Serial.read();
    Serial.println();
  }
  if (val == '1')
  { digitalWrite(relay1, LOW);

  }
  else if (val == '2')
  {
    digitalWrite(relay1, HIGH);
  }
  else if (val == '3')
  {
    digitalWrite(relay2, LOW);
  }
  else if (val == '4')
  {
    digitalWrite(relay2, HIGH);
  }

  delay(100);
}
