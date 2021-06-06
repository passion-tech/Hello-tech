int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int LED6 = 8;
int LED7 = 7;
int LED8 = 6;
int LED9 = 5;
int LED10 = 4;



void setup() {
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
   pinMode(LED5, OUTPUT);
   pinMode(LED6, OUTPUT);
   pinMode(LED7, OUTPUT);
   pinMode(LED8, OUTPUT);
   pinMode(LED9, OUTPUT);
   pinMode(LED10, OUTPUT);
}


void loop() 
{
  digitalWrite(LED1, HIGH);    // turn on LED1 
  delay(200);                  // wait for 200ms
  digitalWrite(LED2, HIGH);    // turn on LED2
  delay(00);                  // wait for 200ms       
  digitalWrite(LED3, HIGH);    // turn on LED3 
  delay(200);                  // wait for 200ms
  digitalWrite(LED4, HIGH);    // turn on LED4
  delay(200);                  // wait for 200ms
  digitalWrite(LED5, HIGH);    // turn on LED5
  delay(200);                  // wait for 200ms
  digitalWrite(LED6, HIGH);    // turn on LED6
  delay(200);                  // wait for 200ms
  digitalWrite(LED7, HIGH);    // turn on LED7
  delay(200);                  // wait for 200ms
  digitalWrite(LED8, HIGH);    // turn on LED8
  delay(200);                  // wait for 200ms
  digitalWrite(LED9, HIGH);    // turn on LED9
  delay(200);                  // wait for 200ms
  digitalWrite(LED10, HIGH);    // turn on LED10
  delay(200);
  // wait for 200ms
  
  digitalWrite(LED1, LOW);     // turn off LED1
  delay(300);                  // wait for 300ms
  digitalWrite(LED2, LOW);     // turn off LED2
  delay(300);                  // wait for 300ms
  digitalWrite(LED3, LOW);     // turn off LED3
  delay(300);                  // wait for 300ms
  digitalWrite(LED4, LOW);     // turn off LED4
  delay(300);                  // wait for 300ms
  digitalWrite(LED5, LOW);     // turn off LED5
  delay(300);                  // wait for 300ms
  digitalWrite(LED6, LOW);     // turn off LED6
  delay(300);                  // wait for 300ms
  digitalWrite(LED7, LOW);     // turn off LED7
  delay(300);                  // wait for 300ms
  digitalWrite(LED8, LOW);     // turn off LED8
  delay(300);                  // wait for 300ms
  digitalWrite(LED9, LOW);     // turn off LED9
  delay(300);                  // wait for 300ms
  digitalWrite(LED10, LOW);
  delay(300);
  // wait for 300ms before running program all over again
}
