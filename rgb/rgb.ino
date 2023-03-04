// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char* ssid     = "desn't free";
const char* password = "n'estpaslibre";

// Set web server port number to 80
WiFiServer server(80);

// Decode HTTP GET value
String redString = "0";
String greenString = "0";
String blueString = "0";
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;

// Variable to store the HTTP req  uest
String header;

// Red, green, and blue pins for PWM control
const int redPin = 13;     // 13 corresponds to GPIO13
const int greenPin = 14;   // 12 corresponds to GPIO12
const int bluePin = 12;    // 14 corresponds to GPIO14

// Setting PWM frequency, channels and bit resolution
const int freq = 5000;
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;
// Bit resolution 2^8 = 256
const int resolution = 8;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

int r=0;
int g=0;
int b=0;

void setup() {
  Serial.begin(115200);
  // configure LED PWM functionalitites
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(redPin, redChannel);
  ledcAttachPin(greenPin, greenChannel);
  ledcAttachPin(bluePin, blueChannel);
  
  // Connect to Wi-Fi network with SSID and password
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

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
                   
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<body><h1>RGB Led</h1>");
            client.println("<form method='GET' action='./'>");
            client.println("<input type=\"text\" name=\"R\"/>");
            client.println("<input type=\"text\" name=\"G\"/>");
            client.println("<input type=\"text\" name=\"B\"/>");
            client.println("<input type='submit' onClick=location.href='./?LED=ON'/>");
            client.println("</form>");
            client.println("</body></html>");
            client.println();

            String params = client.readStringUntil('r');
            //if(lineal.indexOf("LED=ON") > 0 ){
             // String params = client.readStringUntil('\r');
              int p1 = params.indexOf("R=") + 4;
              int p2 = params.indexOf("&", p1);
              r = params.substring(p1, p2).toInt();
              p1 = params.indexOf("G=") + 6;
              p2 = params.indexOf("&", p1);
              g = params.substring(p1, p2).toInt();
              p1 = params.indexOf("B=" + 5);
              p2 = params.indexOf(" ", p1);
              b = params.substring(p1, p2).toInt();
/*
              analogWrite(redPin, r);
              analogWrite(greenPin, g);
              analogWrite(bluePin, b);*/
            //}
              Serial.println("---");
              Serial.println(r);
              Serial.println(g);
              Serial.println(b);
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c; 
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
