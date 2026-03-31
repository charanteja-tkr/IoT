#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN A5

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}