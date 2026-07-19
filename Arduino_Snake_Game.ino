#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);


// Joystick pins
#define JOY_X A0
#define JOY_Y A1
#define BUTTON 2



#define MAX_LENGTH 100


int snakeX[MAX_LENGTH];
int snakeY[MAX_LENGTH];


int snakeLength;

int dirX;
int dirY;


int foodX;
int foodY;


int score;

int speedDelay;

bool gameOver;



void setup()
{

  pinMode(BUTTON, INPUT_PULLUP);


  display.begin(
    SSD1306_SWITCHCAPVCC,
    0x3C
  );


  randomSeed(analogRead(A3));


  startGame();

}



void loop()
{

  if(gameOver)
  {

    display.clearDisplay();


    display.setTextColor(WHITE);


    display.setTextSize(2);

    display.setCursor(15,15);
    display.println("GAME");


    display.setCursor(15,35);
    display.println("OVER");


    display.setTextSize(1);

    display.setCursor(35,55);
    display.print("Score ");
    display.print(score);



    display.display();



    if(digitalRead(BUTTON)==LOW)
    {
      delay(300);
      startGame();
    }


    return;

  }



  readJoystick();


  moveSnake();


  checkGame();


  drawScreen();



  delay(speedDelay);

}




void startGame()
{

  snakeLength = 5;


  dirX = 1;
  dirY = 0;


  score = 0;


  speedDelay = 250;


  gameOver=false;



  for(int i=0;i<snakeLength;i++)
  {

    snakeX[i] = 60 - i*4;
    snakeY[i] = 32;

  }


  createFood();

}




void readJoystick()
{

 int x = analogRead(JOY_X);
 int y = analogRead(JOY_Y);



 if(x < 300 && dirX != 1)
 {
   dirX=-1;
   dirY=0;
 }


 if(x > 700 && dirX != -1)
 {
   dirX=1;
   dirY=0;
 }


 if(y < 300 && dirY != 1)
 {
   dirX=0;
   dirY=-1;
 }


 if(y > 700 && dirY != -1)
 {
   dirX=0;
   dirY=1;
 }


}




void moveSnake()
{


 for(int i=snakeLength-1;i>0;i--)
 {

   snakeX[i]=snakeX[i-1];
   snakeY[i]=snakeY[i-1];

 }


 snakeX[0]+=dirX*4;
 snakeY[0]+=dirY*4;


}




void checkGame()
{


 // hit wall

 if(
 snakeX[0]<0 ||
 snakeX[0]>124 ||
 snakeY[0]<0 ||
 snakeY[0]>60
 )
 {
   gameOver=true;
 }



 // hit body

 for(int i=1;i<snakeLength;i++)
 {

  if(
   snakeX[0]==snakeX[i] &&
   snakeY[0]==snakeY[i]
  )
  {
    gameOver=true;
  }

 }




 // eat food

 if(
 abs(snakeX[0]-foodX)<5 &&
 abs(snakeY[0]-foodY)<5
 )
 {

   score++;


   if(snakeLength < MAX_LENGTH)
   {
     snakeLength++;
   }



   // faster after eating

   if(speedDelay > 80)
   {
     speedDelay -= 10;
   }


   createFood();

 }


}





void createFood()
{

 foodX=random(0,31)*4;
 foodY=random(1,15)*4;

}





void drawScreen()
{

 display.clearDisplay();



 // food

 display.fillCircle(
  foodX,
  foodY,
  3,
  WHITE
 );



 // snake

 for(int i=0;i<snakeLength;i++)
 {

  display.fillRect(
    snakeX[i],
    snakeY[i],
    4,
    4,
    WHITE
  );

 }




 display.setTextSize(1);
 display.setCursor(0,0);


 display.print("Score:");
 display.print(score);



 display.display();

}