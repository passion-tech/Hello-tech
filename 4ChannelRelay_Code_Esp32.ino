// Define relay pins
int relay1 = 14;  
int relay2 = 27;  
int relay3 = 26;  
int relay4 = 25;  

void setup() {
  // Set relay pins as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  // Start with all relays OFF
  digitalWrite(relay1, HIGH); // Use HIGH for OFF (if active LOW relay)
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}

void loop() {
  // Relay 1 ON
  digitalWrite(relay1, LOW);  
  delay(1000);
  digitalWrite(relay1, HIGH);
  delay(1000);

  // Relay 2 ON
  digitalWrite(relay2, LOW);  
  delay(1000);
  digitalWrite(relay2, HIGH);
  delay(1000);

  // Relay 3 ON
  digitalWrite(relay3, LOW);  
  delay(1000);
  digitalWrite(relay3, HIGH);
  delay(1000);

  // Relay 4 ON
  digitalWrite(relay4, LOW);  
  delay(1000);
  digitalWrite(relay4, HIGH);
  delay(1000);
}
