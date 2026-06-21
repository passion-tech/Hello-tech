const int xPin = A0;
const int yPin = A1;

const int ledUp = 8;
const int ledDown = 9;
const int ledLeft = 10;
const int ledRight = 11;

void setup() {
  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int xVal = analogRead(xPin);
  int yVal = analogRead(yPin);

  // Turn all LEDs OFF
  digitalWrite(ledUp, LOW);
  digitalWrite(ledDown, LOW);
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, LOW);

  // Up
  if (yVal > 800) {
    digitalWrite(ledUp, HIGH);
    Serial.println("UP");
  }

  // Down
  else if (yVal < 200) {
    digitalWrite(ledDown, HIGH);
    Serial.println("DOWN");
  }

  // Right
  else if (xVal > 800) {
    digitalWrite(ledRight, HIGH);
    Serial.println("RIGHT");
  }

  // Left
  else if (xVal < 200) {
    digitalWrite(ledLeft, HIGH);
    Serial.println("LEFT");
  }

  delay(100);
}