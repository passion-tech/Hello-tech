#include <SPI.h>
#include <Wire.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN  10

#define STATE_STARTUP       0
#define STATE_STARTING      1
#define STATE_WAITING       2
#define STATE_SCAN_INVALID  3
#define STATE_SCAN_VALID    4
#define STATE_SCAN_MASTER   5
#define STATE_ADDED_CARD    6
#define STATE_REMOVED_CARD  7

#define REDPIN 4
#define GREENPIN 3
#define Relay 2

const int cardArrSize = 10;
const int cardSize    = 4;
byte cardArr[cardArrSize][cardSize];
byte masterCard[cardSize] = {43,254,76,12};   //Change Master Card ID
byte readCard[cardSize];
byte cardsStored = {38,208,125,248};{53,229,160,51};

// Create MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);
// Set the LCD I2C address

byte currentState = STATE_STARTUP;
unsigned long LastStateChangeTime;
unsigned long StateWaitTime;

//------------------------------------------------------------------------------------
int readCardState()
{
  int index;

  Serial.print("Card Data - ");
  for(index = 0; index < 4; index++)
  {
    readCard[index] = mfrc522.uid.uidByte[index];

    
    Serial.print(readCard[index]);
    if (index < 3)
    {
      Serial.print(",");
    }
  }
  Serial.println(" ");

  //Check Master Card
  if ((memcmp(readCard, masterCard, 4)) == 0)
  {
    return STATE_SCAN_MASTER;
  }

  if (cardsStored == 0)
  {
    return STATE_SCAN_INVALID;
  }

  for(index = 0; index < cardsStored; index++)
  {
    if ((memcmp(readCard, cardArr[index], 4)) == 0)
    {
      return STATE_SCAN_VALID;
    }
  }

 return STATE_SCAN_INVALID;
}

//------------------------------------------------------------------------------------
void addReadCard()
{
  int cardIndex;
  int index;

  if (cardsStored <= 20)
  {
    cardsStored++;
    cardIndex = cardsStored;
    cardIndex--;
  }

  for(index = 0; index < 4; index++)
  {
    cardArr[cardIndex][index] = readCard[index];
  }
}

//------------------------------------------------------------------------------------
void removeReadCard() 
{     
  int cardIndex;
  int index;
  boolean found = false;
  
  for(cardIndex = 0; cardIndex < cardsStored; cardIndex++)
  {
    if (found == true)
    {
      for(index = 0; index < 4; index++)
      {
        cardArr[cardIndex-1][index] = cardArr[cardIndex][index];
        cardArr[cardIndex][index] = 0;
      }
    }
    
    if ((memcmp(readCard, cardArr[cardIndex], 4)) == 0)
    {
      found = true;
    }
  }

  if (found == true)
  {
    cardsStored--;
  }
}

//------------------------------------------------------------------------------------
void updateState(byte aState)
{
  if (aState == currentState)
  {
    return;
  }

  // do state change
  switch (aState)
  {
    case STATE_STARTING:
      StateWaitTime = 1000;
      digitalWrite(REDPIN, HIGH);
      digitalWrite(GREENPIN, LOW);
      break;
    case STATE_WAITING:
      StateWaitTime = 0;
      digitalWrite(REDPIN, LOW);
      digitalWrite(GREENPIN, LOW);
      break;
    case STATE_SCAN_INVALID:
      if (currentState == STATE_SCAN_MASTER)
      {
        addReadCard();
        aState = STATE_ADDED_CARD;
        StateWaitTime = 2000;
        digitalWrite(REDPIN, LOW);
        digitalWrite(GREENPIN, HIGH);
      }
      else if (currentState == STATE_REMOVED_CARD)
      {
        return;
      }
      else
      {
        StateWaitTime = 2000;
        digitalWrite(REDPIN, HIGH);
        digitalWrite(GREENPIN, LOW);
      }
      break;
    case STATE_SCAN_VALID:
      if (currentState == STATE_SCAN_MASTER)
      {
        removeReadCard();
        aState = STATE_REMOVED_CARD;
        StateWaitTime = 2000;
        digitalWrite(REDPIN, LOW);
        digitalWrite(GREENPIN, HIGH);
      }
      else if (currentState == STATE_ADDED_CARD)
      {
        return;
      }
      else
      {
        StateWaitTime = 2000;
        digitalWrite(REDPIN, LOW);
        digitalWrite(GREENPIN, HIGH);
        digitalWrite(Relay,LOW);
        delay(3000);
        digitalWrite(Relay,HIGH);
      }
      break;
    case STATE_SCAN_MASTER:
      StateWaitTime = 5000;
      digitalWrite(REDPIN, LOW);
      digitalWrite(GREENPIN, HIGH);
      break;
  }

  currentState = aState;
  LastStateChangeTime = millis();
}

void setup() 
{
  SPI.begin();         // Init SPI Bus
  mfrc522.PCD_Init();  // Init MFRC522

  LastStateChangeTime = millis();
  updateState(STATE_STARTING);

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay,HIGH);

  Serial.begin(9600);
}

void loop() 
{
  byte cardState;

  if ((currentState != STATE_WAITING) &&
      (StateWaitTime > 0) &&
      (LastStateChangeTime + StateWaitTime < millis()))
  {
    updateState(STATE_WAITING);
  }

  // Look for new cards 
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  { 
    return; 
  } 
  
  // Select one of the cards 
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  { 
    return; 
  }

  cardState = readCardState();
  updateState(cardState);
}
