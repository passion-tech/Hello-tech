#include <Stepper.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

Stepper my_Stepper(200, D1, D2, D3, D4);

bool Right = false;
bool Left = false;

char auth[] = " HEUnQPNccROPgUKKSCg1SmPi8wK6bLtV ";
char ssid[] = "TELI";
char pass[] = "telizar1991";


void setup(){

  Serial.begin(9600);                                 // baudrate for serial comunication
  Blynk.begin(auth, ssid, pass);                      // network information 
  my_Stepper.setSpeed(100);                            // Speed for stepper motor
  
}


BLYNK_WRITE(V1){                                      // read input from virtual pin V1
  Right = param.asInt();                              // assigning incoming value from pin V§1 to a variable
  }
  
BLYNK_WRITE(V2){                                      // read input from virtual pin V2
  Left = param.asInt();                               // assigning incoming value from pin V0 to a variable
  }
  
void Stepper1 (int Direction, int Rotation){          // function for stepper motor control with 2 parameters
  for (int i = 0; i < Rotation; i++){                 // for loop 
  my_Stepper.step(Direction * 200);                   // 200 is 360 degree => change value if smaller then 360 degree is needing
  Blynk.run();
  }
}

void loop() {   
  
  Blynk.run();
  
  if (Right){                                          // if condition 
  Stepper1(1, 10);                                     // steppermotor rotates 10 times 360 degree right
  Serial.println("Right turn");
  }
  delay(10);                                           // delay 20ms
  
  if (Left){                                           // if condition 
  Stepper1(-1, 10);                                    // steppermotor rotates 10 times 360 degree left
  Serial.println("Left turn");
  }
  delay(10);                                           // delay 20ms
}
