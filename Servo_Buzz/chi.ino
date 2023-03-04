#include <Servo.h>

const int Trigger = 2;   
const int Echo = 3;
const int pinBuzzer = 10;

Servo servoMotor;

void setup() {

  Serial.begin(9600);
  servoMotor.attach(9);
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}
void loop() {
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;
  Serial.println(d);
  if(d < 15){

  servoMotor.write(10);
    tone(pinBuzzer, 440);

    delay(1500);
    noTone(pinBuzzer);
  }
  else{
    servoMotor.write(90);
    noTone(pinBuzzer);
  }
}