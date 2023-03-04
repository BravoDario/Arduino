#include <WiFi.h>

const char* ssid = "INFINITUM9DF3_2.4";//"desn't free";
const char* password = "1492743743";//"n'estpaslibre";

WiFiServer server(80);

const int redPin = 13;
const int greenPin = 14; 
const int bluePin = 12; 

int r;
int g;
int b;

void setup() {
  Serial.begin(115200);
  delay(10);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {

WiFiClient client = server.available();
  if(client)//Si hay un cliente presente
  {
    Serial.println("Nuevo Cliente");

    String currentLine ="";

    while(client.connected()){
      if(client.available()){
        char c = client.read();
        Serial.write(c);
        if(c == '\n'){
          if(currentLine.length() == 0){
            client.println("HTTP/1.1 200 OK");
            client.println("Content.type:text/html");
            client.println();
            
            //Pagina html para en el navegador
            client.println("<!DOCTYPE HTML>");
            client.println("<html>");
            client.println("<head><title>UTL Electronics</title></head>");
            client.println("<body>");
            client.println("<h1 align='center'>Test ESP32</h1>");
            client.println("<div style='text-align:center;'>");
            client.println("<br/>");

            client.println("<form method='GET' action='./LED=ON'>");
            client.println("<input type=\"text\" name='R'/>");
            client.println("<input type=\"text\" name='G'/>");
            client.println("<input type=\"text\" name='B'/>");
            client.println("<input type='submit' id='snd'/>");
            client.println("</form>");
            
            client.println("</div>");
            client.println("<br />");
            client.println("</div>");
            client.println("</body>");
            client.println("</html>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r'){
          currentLine += c;
        }
        
        String lineal = client.readStringUntil('r');
            
            if(lineal.indexOf("LED=ON") > 0 ){
              String params = client.readStringUntil('\r');
              int p1 = params.indexOf("R=") + 4;
              int p2 = params.indexOf("&", p1);
              r = params.substring(p1, p2).toInt();
              p1 = params.indexOf("G=") + 6;
              p2 = params.indexOf("&", p1);
              g = params.substring(p1, p2).toInt();
              p1 = params.indexOf("B=" + 5);
              p2 = params.indexOf(" ", p1);
              b = params.substring(p1, p2).toInt();

              analogWrite(redPin, r);
              analogWrite(greenPin, g);
              analogWrite(bluePin, b);

              Serial.println("------");
              Serial.println(r);
              Serial.println(g);
              Serial.println(b);
            }
      }
    }
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
