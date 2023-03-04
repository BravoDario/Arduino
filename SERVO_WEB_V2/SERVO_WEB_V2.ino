#include <WiFi.h>
#include <ESP32Servo.h>
Servo servoMotor1; 

const char* ssid = "desn't free";
const char* password = "n'estpaslibre";

WiFiServer server(80);
void setup()
{
    Serial.begin(115200);
    servoMotor1.attach(13);
    pinMode(2, OUTPUT);
    delay(10);
    Serial.print("Conectando a ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("Conectado a red Wifi.");
    Serial.println("Dirección IP ");
    Serial.println(WiFi.localIP());  
    server.begin();
    digitalWrite(2, HIGH);
}
int value = 0;
void loop(){
 WiFiClient client = server.available();
  if (client) {                         
    Serial.println("Nuevo cliente");    
    String currentLine = "";            
    while (client.connected()) {        
      if (client.available()) {         
        char c = client.read();         
        Serial.write(c);                
        if (c == '\n') {                
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            
            client.print("Click <a href=\"/ABRIR\">Abrir</a> Para Abrir la puerta.<br>");
            client.print("Click <a href=\"/CERRAR\">Cerrar</a> Para Cerrar la puerta.<br>");
             client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
        if (currentLine.endsWith("GET /ABRIR")) {
          servoMotor1.write(110);            
        }
        if (currentLine.endsWith("GET /CERRAR")) {
          servoMotor1.write(180);           
        }
      }
    }
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
