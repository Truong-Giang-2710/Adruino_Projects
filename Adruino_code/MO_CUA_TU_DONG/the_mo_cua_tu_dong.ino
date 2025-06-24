
// Дмитрий Осипов. http://www.youtube.com/user/d36073?feature=watch

#include <SPI.h>
#include <MFRC522.h> // thu vien "RFID".
const int LED2 = 2; // LED xanh

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);       
unsigned long uidDec, uidDecTemp; // hien thi so UID dang thap phan
byte bCounter, readBit;
unsigned long ticketNumber;

void setup() {
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);     
  SPI.begin();            
  mfrc522.PCD_Init();     
}

void loop() {
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  uidDec = 0;
  } 
  Serial.print("            [");
  Serial.print(uidDec);
  if(uidDec == 696335238){
    digitalWrite(LED1=1);
    digitalRead(LED1=0));
    Serial.println("Xin chao ban");
    delay(5000);
  }
  else{
    digitalWrite(LED1=0);
    digitalRead(LED1=1));
    delay(5000);
  }
  //--------------------------------
  if(uidDec == 3501146325){
    digitalWrite(LED2=1),
    digitalRead(LED2=0));
    delay(5000);
  }else{
    digitalWrite(LED2=0),
    digitalRead(LED2=1));
    delay(5000);
  }
  Serial.println("]");
  Serial.println("]");
  // Halt PICC
  mfrc522.PICC_HaltA();                       

}

