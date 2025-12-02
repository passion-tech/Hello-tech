#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22
#define RELAY_PIN 26  // Relay input pin (Active LOW)

MFRC522 rfid(SS_PIN, RST_PIN);

// 3 allowed cards
byte card1[] = {0x4A, 0xBA, 0xC6, 0x23};
byte card2[] = {0xCB, 0x98, 0x47, 0x9E};
byte card3[] = {0x26, 0xD0, 0x7D, 0xF8};

bool checkCard(byte *allowedUID) {
  for (byte i = 0; i < rfid.uid.size; i++) {
    if (rfid.uid.uidByte[i] != allowedUID[i]) {
      return false;
    }
  }
  return true;
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Relay OFF (Active LOW)

  Serial.println("Scan your RFID card...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("Scanned UID: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  bool access = false;

  if (checkCard(card1)) access = true;
  if (checkCard(card2)) access = true;
  if (checkCard(card3)) access = true;

  if (access) {
    Serial.println("ACCESS GRANTED");
    digitalWrite(RELAY_PIN, LOW);   // Relay ON
    delay(3000);                    // ON for 5 sec
    digitalWrite(RELAY_PIN, HIGH);  // Relay OFF
  } else {
    Serial.println("ACCESS DENIED");
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
