/*
   Initial Author: ryand1011 (https://github.com/ryand1011)

   Reads data written by a program such as "rfid_write_personal_data.ino"

   See: https://github.com/miguelbalboa/rfid/tree/master/examples/rfid_write_personal_data

   Uses MIFARE RFID card using RFID-RC522 reader
   Uses MFRC522 - Library
   -----------------------------------------------------------------------------------------
               MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
               Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
   Signal      Pin          Pin           Pin       Pin        Pin              Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
   SPI SS      SDA(SS)      10            53        D10        10               10
   SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
   SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
   SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15

   More pin layouts for other boards can be found here: https://github.com/miguelbalboa/rfid#pin-layout
*/
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance


bool rfid_tag_present_prev = false;
bool rfid_tag_present = false;
int _rfid_error_counter = 0;
bool _tag_found = false;
uint32_t lastCard;

uint32_t uidToUint32(MFRC522::Uid uid) {
  // S'assurer que l'UID est de 4 octets
  if (uid.size != 4) {
    return 0; // Retourner 0 en cas de taille incorrecte de l'UID
  }

  // Concaténer les octets de l'UID dans un uint32_t
  uint32_t result = 0;
  for (int i = 0; i < 4; i++) {
    result <<= 8;
    result |= uid.uidByte[i];
  }
  return result;
}


void initNFC() {
  SPI.begin();                                                  // Init SPI bus
  mfrc522.PCD_Init();
}

void loopNFC() {
  rfid_tag_present_prev = rfid_tag_present;

  _rfid_error_counter += 1;
  if (_rfid_error_counter > 2) {
    _tag_found = false;
  }

  // Detect Tag without looking for collisions
  byte bufferATQA[2];
  byte bufferSize = sizeof(bufferATQA);

  // Reset baud rates
  mfrc522.PCD_WriteRegister(mfrc522.TxModeReg, 0x00);
  mfrc522.PCD_WriteRegister(mfrc522.RxModeReg, 0x00);
  // Reset ModWidthReg
  mfrc522.PCD_WriteRegister(mfrc522.ModWidthReg, 0x26);

  MFRC522::StatusCode result = mfrc522.PICC_RequestA(bufferATQA, &bufferSize);

  if (result == mfrc522.STATUS_OK) {
    if ( ! mfrc522.PICC_ReadCardSerial()) { //Since a PICC placed get Serial and continue
      return;
    }
    _rfid_error_counter = 0;
    _tag_found = true;
  }

  rfid_tag_present = _tag_found;

  // rising edge
  if (rfid_tag_present && !rfid_tag_present_prev) {
    uint32_t cardid = uidToUint32(mfrc522.uid);
    Serial.print("nfcEnter ");
    Serial.println(cardid);
    lastCard = cardid;
    digitalWrite(LED_PIN, HIGH);
  }

  // falling edge
  if (!rfid_tag_present && rfid_tag_present_prev) {
    Serial.print("nfcExit ");
    Serial.println(lastCard);
    lastCard = 0;
    digitalWrite(LED_PIN, LOW);
  }

  //mfrc522.PICC_HaltA();
  //mfrc522.PCD_StopCrypto1();
}
