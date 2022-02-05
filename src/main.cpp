//Para subir el programa en Linux usamos el comando: 
// sudo chmod a+rw /dev/ttyUSB0

#include <Arduino.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

///Codigo html/// 
#include <index.h>


const char* ssid = "MEGACABLE-979F";
const char* password = "8eAYgaeY"; 

//INiciamos el sevidor en el puerto 80: 
ESP8266WebServer server(80);

//Manejo de peticiones: 
void handle_root(){
  server.send(200, "text/html", html); 
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password); 
  Serial.print("\n\r ....");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("No connected");
  }

  Serial.println("Connected to wifi"); 
  Serial.println("ip = ");
  Serial.println(WiFi.localIP()); 

  /////// Manejo de las req: /////
  server.on("/", handle_root); 
  
  server.begin();
  Serial.println("Server start"); 
}

void loop() {
  server.handleClient();
  
}