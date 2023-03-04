#include <LiquidCrystal.h>

int seconds = 0;
int red = 6;
int green = 8;
String texto="";


void setup()
{
  Serial.begin(9600);
}

void loop()
{ int c=0;
  texto=Serial.readString();
  Serial.println(texto);
  
}
