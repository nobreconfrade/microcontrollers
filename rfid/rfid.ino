#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <MFRC522Debug.h>
#include <require_cpp11.h>
#include <MFRC522Hack.h>
#include <deprecated.h>
#include <SoftwareSerial.h>
#include <SPI.h>

#define SS_PIN 10
#define RST_PIN 9
#define RED 4
#define GRE 3

MFRC522 mfrc522(SS_PIN,RST_PIN);
void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Pass your cardkey.");
  pinMode(RED,OUTPUT);
  pinMode(GRE,OUTPUT);
}

void loop() {
  digitalWrite(GRE,LOW);
  digitalWrite(RED,HIGH);
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  Serial.println("UID from tag:");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  //delay(10000);
  content.toUpperCase();
  if(content.substring(1) == "B5 CA A6 56"){
    digitalWrite(RED,LOW);
    digitalWrite(GRE,HIGH);
    delay(10000);
  }
}
