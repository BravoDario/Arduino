int ZumbadorPin=2;
int c=261;
int d=294;
int e=329;
int f=349;
int g=391;
int gS=415;
int a=440;
int aS=455;
int b=466;
int cH=523;
int cSH=554;
int dH=587;
int dSH=622;
int eH=659;
int fH=698;
int fSH=740;


int gH=783;
int gSH=830;
int aH=880;
int trig=4;
int echo=5;
int dist, temp;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  pinMode(ZumbadorPin, OUTPUT); // definimos la variable ZumbadorPin como una salida.

}   
    
void loop()  
{  
    digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  temp = pulseIn(echo, HIGH);
  dist = temp*0.01724;
  Serial.println(dist);

  if(dist<=15){
  marchaImperial();
    }
    else{
  Serial.println("hola :) ");
    }
  delay(1000);
}
int marchaImperial(){
    tone(ZumbadorPin, a);
    delay(500+50);
    tone(ZumbadorPin, a);
    delay(500+50);    
    tone(ZumbadorPin, a);
    delay(500+50);
    tone(ZumbadorPin, f); 
    delay(350+50);
    tone(ZumbadorPin, cH);
    delay(150+50);
   
    tone(ZumbadorPin, a);
    delay(500+50);
    tone(ZumbadorPin, f);
    delay(350+50);
    tone(ZumbadorPin, cH);
    delay(150+50);
    tone(ZumbadorPin, a);  
    delay(1000+50);
  
    tone(ZumbadorPin, eH);
    delay(500+50);
    tone(ZumbadorPin, eH);
    delay(500+50);
    tone(ZumbadorPin, eH);
    delay(500+50);  
    tone(ZumbadorPin, fH);
    delay(350+50);
    tone(ZumbadorPin, cH);
    delay(150+50);
    
    tone(ZumbadorPin, gS);
    delay(500+50);
    tone(ZumbadorPin, f);
    delay(350+50);
    tone(ZumbadorPin, cH);
    delay(150+50);
    tone(ZumbadorPin, a);
    delay(1000+50);
   
    tone(ZumbadorPin, aH);
    delay(500+50);
    tone(ZumbadorPin, a);
    delay(350+50);
    tone(ZumbadorPin, a);
    delay(150+50);
    tone(ZumbadorPin, aH);
    delay(500+50);
    tone(ZumbadorPin, gSH);
    delay(250+50);
    tone(ZumbadorPin, gH);
    delay(250+50);
   
    tone(ZumbadorPin, fSH);
    delay(125+50);
    tone(ZumbadorPin, fH);
    delay(125+50);   
    tone(ZumbadorPin, fSH);
    delay(250+50);
    delay(250);
    tone(ZumbadorPin, aS);
    delay(250+50);   
    tone(ZumbadorPin, dSH);
    delay(500+50);
    tone(ZumbadorPin, dH);
    delay(250+50);
    tone(ZumbadorPin, cSH);
    delay(250+50); 
   
    // virtuosismo :)))
   
    tone(ZumbadorPin, cH);
    delay(125+50); 
    tone(ZumbadorPin, b);
    delay(125+50);
    tone(ZumbadorPin, cH);
    delay(250+50);    
    delay(250);
    tone(ZumbadorPin, f);
    delay(125+50);
    tone(ZumbadorPin, gS);
    delay(500+50);
    tone(ZumbadorPin, f);
    delay(375+50);
    tone(ZumbadorPin, a);
    delay(125+50);
   
    tone(ZumbadorPin, cH);
    delay(500+50);
    tone(ZumbadorPin, a); 
    delay(375+50);
    tone(ZumbadorPin, cH);
    delay(125+50);
    tone(ZumbadorPin, eH);
    delay(1000+50);

   
    tone(ZumbadorPin, aH);
    delay(500+50);
    tone(ZumbadorPin, a);
    delay(350+50);
    tone(ZumbadorPin, a);
    delay(150+50);
    tone(ZumbadorPin, aH);
    delay(500+50);
    tone(ZumbadorPin, gSH);
    delay(250+50);
    tone(ZumbadorPin, gH);
    delay(250+50);
   
    tone(ZumbadorPin, fSH);
    delay(125+50);
    tone(ZumbadorPin, fH); 
    delay(125+50); 
    tone(ZumbadorPin, fSH);
    delay(250+50);
    delay(250);
    tone(ZumbadorPin, aS); 
    delay(250+50); 
    tone(ZumbadorPin, dSH); 
    delay(500+50);
    tone(ZumbadorPin, dH); 
    delay(250+50);
    tone(ZumbadorPin, cSH);
    delay(250+50); 

   
    tone(ZumbadorPin, cH); 
    delay(125+50);
    tone(ZumbadorPin, b); 
    delay(125+50);
    tone(ZumbadorPin, cH);
    delay(250+50);     
    delay(250);
    tone(ZumbadorPin, f);
    delay(250+50);
    tone(ZumbadorPin, gS);
    delay(500+50);
    tone(ZumbadorPin, f); 
    delay(375+50);
    tone(ZumbadorPin, cH);
    delay(125+50);
          
    tone(ZumbadorPin, a);
    delay(500+50);          
    tone(ZumbadorPin, f); 
    delay(375+50);         
    tone(ZumbadorPin, c);
    delay(125+50); 
    tone(ZumbadorPin, a);
    delay(1000+50);      

    delay(200);
}
