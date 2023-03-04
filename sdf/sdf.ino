#include <DHT.h>
//#include <LiquidCrystal.h>
DHT dht(8, DHT11);

int con=0;
String texto="";
char option;
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  Serial.print("d"  "f");
  delay(1000);
  /*float c;
  c=dht.readHumidity();
  
  texto=String(c,2);
    Serial.print(c);
    delay(1000);
  if(Serial.available()>0){
    //leemos la opcion enviada
    Serial.print(texto);
  }else{
    Serial.print(texto);
  }*/
}
