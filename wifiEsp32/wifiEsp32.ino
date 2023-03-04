#include <WiFi.h>


const char* ssid = "desn't free";
const char* password = "n'estpaslibre";
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10);

  //configuracion del GPI02
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  Serial.println();
  Serial.println();
  Serial.print("Conectandose a red : ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("Wifi Conectado");
  server.begin();
  Serial.println("");
  Serial.println("Navegador listo");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if(client)//Si hay un cliente presente
  {
    Serial.println("Nuevo Cliente");
    //esperamos hasta que hayan datos disponibles
    while(!client.available() && client.connected())
    {
      delay(1);
    }
    //Leemos la primera linea de la peticion del cliente
    String lineal = client.readStringUntil('r');

    
    Serial.println(lineal);
    if(lineal.indexOf("LED=ON")>0);
    {
      digitalWrite(2, HIGH);
    }
    if(lineal.indexOf("LED=0FF")>0)
    {
      digitalWrite(2,LOW);
    }
    //cliente.flush();
    Serial.println("Enviando respuesta...");
    //Encabezado http
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close"); //La conexion se cierra despues de finalizar
    client.println();
    //Pagina html para en el navegador
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head><title>UTL Electronics</title></head>");
    client.println("<body>");
    client.println("<h1 align='center'>Test ESP32</h1>");
    client.println("<div style='text-align:center;'>");
    client.println("<br/>");
    client.println("<input placeholder='Rojo' id='txtRed'/>");
    client.println("<input placeholder='Azul' id='txtBlu' />");
    client.println("<input placeholder='Verde' id='txtGre' />");
    client.println("<button onClick=location.href='./?LED=OFF'>Enviar</button>");
    client.println("<br />");
    client.println("</div>");
    client.println("</body>");
    client.println("</html>");
    delay(1);
    Serial.println("respuesta enviada");
    Serial.println();
  }
}
