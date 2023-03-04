#include <Servo.h>

Servo ms;

int pir = 2;
int led = 6;
int trigger = 8; 
int echo = 5;
bool det;

void setup()
{
  Serial.begin(9600);
  ms.attach(3);
  
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  digitalWrite(trigger, LOW);
  ms.write(0);
}

void loop(){
  ms.write(0);
  long t, d;
  int val = digitalRead(pir);
  Serial.println(val);
  if(val==HIGH){
    ms.write(90);
    /*
    digitalWrite(trigger, HIGH);
    delay(10);
    digitalWrite(trigger, LOW);
    t = pulseIn(echo, HIGH);
    d=t/59;
    if(d>7){
      digitalWrite(led, LOW);
    }
    if(d<=7){
      digitalWrite(led, HIGH);
    }*/
    delay(2000);
    ms.write(1);
  }
}
