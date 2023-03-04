#include <DHT.h>
//#include <LiquidCrystal.h>
DHT dht(8, DHT11);
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//String msg = "Humedad = ";

void setup() {
Serial.begin(9600);
dht.begin();
//lcd.begin(16,2);
//lcd.setCursor(0,0);
}
void loop() {
//  delay(2000);
  float h, cent, f, icc, icf;
  String texto, msg;
  char option;
  //lcd.clear();
  //lcd.setCursor(0,0);
  h=dht.readHumidity();
  cent=dht.readTemperature();
  f=dht.readTemperature(true);
  //icc=dht.computeHeatIndex(cent,h,false);
  icf=dht.computeHeatIndex(f,h);
  //
  msg=String(cent, 2);
  Serial.println(msg);
  /*else{
    Serial.println(Serial.available());
  }*/

  //lcd.print(c);
  //Serial.print(texto);
}
