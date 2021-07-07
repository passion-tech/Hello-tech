#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
int Steps=4096; //4096 or 768
int cstep=0;


void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  for(int x=0;x<Steps;x++)
  {
    step1();
    //delay (1);
    delayMicroseconds(2500);
    
  }
  Serial.println("Boom!!");
  delay(1000);
}
void step1()
{
  //stepp 
  switch(cstep)
  {
    case 0:
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    break;
    case 1:
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,HIGH);
    break;
    case 2:
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
     break;
    case 3:
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
     break;
    case 4:
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
     break;
    case 5:
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
     break;
    case 6:
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
     break;
    case 7:
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
     break;
    default:
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    break;
  }
cstep=cstep+1;
if(cstep==8)
{cstep=0;}
}
