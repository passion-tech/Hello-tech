const int buzzerPin = 9;      //define the buzzer pin

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
}
void loop()
{
  for (int i = 200; i <= 800; i++)  // loop from 200 to 800 (frequency)
   {
    tone(buzzerPin, i);
    delay(10);
  }
  delay(5000);                      //3 seconds on highest frequency
  for (int i = 800; i >= 200; i--)  // loop from 200 to 800 (frequency)
  {
    tone(buzzerPin, i);
    delay(2);
  }
}
