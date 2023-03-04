int sensor = A0;
int led = 2;
int rojo = 3;
int amar = 4;
int verd = 5;
int lectura;

unsigned long previousMillisFR = 0;
unsigned long currentMillisFR = 0;
const long intervalFR = 10;

unsigned long previousMillisLuz = 0;
unsigned long currentMillisLuz = 0;
const long intervalLuz = 5000;
int statVer = HIGH;
int statRoj = LOW;
int statAma = LOW;

int cone = 7;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(amar, OUTPUT);
  pinMode(verd, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(cone, INPUT);
}

void loop() {
  currentMillisFR = millis();
  currentMillisLuz = millis();
  int ener = LOW;
  ener = digitalRead(cone);
  //alumbrado público
  if (currentMillisFR - previousMillisFR >= intervalFR) {
    previousMillisFR = currentMillisFR;
    lectura = analogRead(sensor);
    if(lectura>=700){
      digitalWrite(led, HIGH);
    }
    else{
      digitalWrite(led, LOW);
    }
  }

  if(ener==LOW){
    
    Serial.println("0");
    //semáforo
    if (currentMillisLuz - previousMillisLuz >= intervalLuz) {
      previousMillisLuz = currentMillisLuz;
      if(statVer == LOW && statRoj==HIGH){
        statVer = HIGH;
        statRoj = LOW;
      }else if(statAma == LOW && statVer == HIGH){
        statAma = HIGH;
        statVer = LOW;
      }else if(statRoj == LOW && statAma == HIGH){
        statRoj = HIGH;
        statAma = LOW;
      }
    }
  }else{
    Serial.println("1");
    statVer = LOW;
    statRoj = HIGH;
    statAma = LOW;
  }
    digitalWrite(verd, statVer);
    digitalWrite(amar, statAma);  
    digitalWrite(rojo, statRoj);
}
