#include <SPI.h>
#include <MFRC522.h>

int SS_PIN[3] = {5, 7, 9};
int RST_PIN[3] = {4, 6, 8};

MFRC522 rfid1(SS_PIN[0], RST_PIN[0]);
MFRC522 rfid2(SS_PIN[1], RST_PIN[1]);
MFRC522 rfids[3] = {rfid1, rfid2};

//Store NUID
byte nuidPICC[4];

void setup() {
  Serial.begin(9600);
  SPI.begin(); //Init SPI bus
  for (int i = 0; i <= 1; i++)
    rfids[i].PCD_Init(); //Init RC522
}

void loop() {
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (j == i)digitalWrite(SS_PIN[j], 0);
      else digitalWrite(SS_PIN[j], 1);
    }
    //Look for card
    if (rfids[i].PICC_IsNewCardPresent())
      continue;

    //Try if NUID is readable
    if (rfids[i].PICC_ReadCardSerial())
      continue;

    MFRC522::PICC_Type piccType = rfids[i].PICC_GetType(rfids[i].uid.sak);

    //Check if the kind of this card is MIFARE
    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
        piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
        piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
      Serial.println("不支持读取此卡类型");
      continue;
    }

    //Store NUID
    for (byte j = 0; j < 4; j++) {
      nuidPICC[j] = rfids[i].uid.uidByte[j];
    }
    Serial.print("UID");
    Serial.print(i);
    Serial.print(" in HEX");
    printHex(rfids[i].uid.uidByte, rfids[i].uid.size);
    Serial.println();

    Serial.print("UID");
    Serial.print(i);
    Serial.print(" in DEX");
    printDec(rfids[i].uid.uidByte, rfids[i].uid.size);
    Serial.println();

    //Let the holding card be in sleep mode, make sure to read once
    rfids[i].PICC_HaltA();

    //Stop reading
    rfids[i].PCD_StopCrypto1();
  }
}

void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : "");
    Serial.print(buffer[i], HEX);
  }
}

void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : "");
    Serial.print(buffer[i], DEC);
  }
}
