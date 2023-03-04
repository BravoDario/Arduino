int led=13;
char dato;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.read();
    Serial.println(dato);
    if(dato=='1'){
      digitalWrite(led, HIGH);
      Serial.println("encendido");
    }
    else if(dato=='0'){
      digitalWrite(led, LOW);
      Serial.println("Apagado");
    }
    else{
      Serial.println("dif");
    }
    delay(1000);
  }
}
