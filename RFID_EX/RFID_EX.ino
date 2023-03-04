#include <MFRC522.h>
#include <Servo.h>

Servo ms;
int buz = 3;

int rst = 9;
int ss_enb = 10;

MFRC522 rf(ss_enb, rst);

String bufferId = "";
String contrasena ="";

void setup() {
  Serial.begin(9600);
  ms.attach(6);
  pinMode(buz, OUTPUT);
  SPI.begin();
  rf.PCD_Init();
  Serial.println("control iniciado...");
  ms.write(0);
}

void loop() {
  if(rf.PICC_IsNewCardPresent()){
    bufferId = "";
    if(rf.PICC_ReadCardSerial()){
      Serial.println("Card UID: ");
      for(byte i=0;i<rf.uid.size; i++){
        Serial.print(rf.uid.uidByte[i] < 0x10 ? " 0": " ");
        Serial.print(rf.uid.uidByte[i], HEX);
        bufferId = bufferId + String(rf.uid.uidByte[i], HEX);
      }
      Serial.println("");
      Serial.println(bufferId);
      if(bufferId == "acd8580"){
        ms.write(90);
        tone(buz, 440);
      }else {
        tone(buz, 260);
      }
      
      Serial.println("");
      rf.PICC_HaltA();
    }
  }
  delay(1000);
  noTone(buz);
  ms.write(0);
}
