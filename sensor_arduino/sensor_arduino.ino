#include <Servo.h>

Servo ms;
int buz = 4;
int echo = 6;
int trig = 5;
long temp, dist;
int ang = 90;
int cone = 2;

void setup() {
  ms.attach(3);
  Serial.begin(9600);
  pinMode(buz, OUTPUT);
  pinMode(cone, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  ms.write(90);
}

void loop() {
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  temp = pulseIn(echo, HIGH);
  dist = temp*0.01724;
  if(dist<=25){
    Serial.println("1");
    digitalWrite(cone, HIGH);
    for(int i=0;i<90;i++){
      ms.write(ang);
      ang--;
    tone(buz, 440);
      delay(50);
    noTone(buz);
      delay(50);
    }
    digitalWrite(cone, LOW);
  } else if(ms.read()<10){
    for(int i=90;i>0;i--){
      ms.write(ang);
      ang++;
      delay(100);
    }
    digitalWrite(cone, LOW);
  }
    digitalWrite(cone, LOW);
    delay(10);
}
