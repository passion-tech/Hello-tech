#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// Joystick
#define JOY_X A0
#define JOY_Y A1


// Motor A (Left)
#define ENA 9
#define IN1 7
#define IN2 8


// Motor B (Right)
#define ENB 10
#define IN3 5
#define IN4 6


int xValue;
int yValue;

int motorSpeed;

String direction;


void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  Serial.begin(9600);


  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    while(true);
  }


  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

}



void loop() {


  xValue = analogRead(JOY_X);
  yValue = analogRead(JOY_Y);


  int center = 512;
  int deadZone = 100;


  // STOP
  if(abs(xValue-center)<deadZone && abs(yValue-center)<deadZone)
  {

    stopMotor();

    direction="STOP";
    motorSpeed=0;

  }


  // FORWARD

  else if(yValue < 400)
  {

    forward();

    direction="FORWARD";

    motorSpeed=map(400-yValue,0,400,0,255);

  }



  // BACKWARD

  else if(yValue > 600)
  {

    backward();

    direction="BACKWARD";

    motorSpeed=map(yValue-600,0,423,0,255);

  }



  // LEFT

  else if(xValue < 400)
  {

    left();

    direction="LEFT";

    motorSpeed=map(400-xValue,0,400,0,255);

  }



  // RIGHT

  else if(xValue > 600)
  {

    right();

    direction="RIGHT";

    motorSpeed=map(xValue-600,0,423,0,255);

  }


  displayOLED();


  delay(50);

}


// ================= MOTOR FUNCTIONS =================


void forward()
{

digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);


analogWrite(ENA,200);
analogWrite(ENB,200);

}



void backward()
{

digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);


analogWrite(ENA,200);
analogWrite(ENB,200);

}



void left()
{

// Left motor slow
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);


// Right motor forward
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);


analogWrite(ENA,120);
analogWrite(ENB,220);

}



void right()
{

// Left motor forward
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);


// Right motor slow
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);


analogWrite(ENA,220);
analogWrite(ENB,120);

}



void stopMotor()
{

digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);

digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);


analogWrite(ENA,0);
analogWrite(ENB,0);

}



// ================= OLED =================


void displayOLED()
{

display.clearDisplay();

display.setTextSize(1);


display.setCursor(0,0);
display.println("Joystick Robot");


display.setCursor(0,18);
display.print("Direction:");
display.println(direction);


display.setCursor(0,35);
display.print("Speed:");
display.print(map(motorSpeed,0,255,0,100));
display.println("%");


display.setCursor(0,52);
display.print("X:");
display.print(xValue);

display.print(" Y:");
display.print(yValue);


display.display();

}