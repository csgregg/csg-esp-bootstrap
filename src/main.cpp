#include <FS.h> 
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include "..\local\local-settings.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWD;
ESP8266WebServer server(80);


void filefont1()
{
  File file = SPIFFS.open("/font.woff", "r"); 
  size_t sent = server.streamFile(file, "application/font-woff");
  sent = sent;
}

void fileindex()
{
  File file = SPIFFS.open("/index.html.gz", "r"); 
  size_t sent = server.streamFile(file, "text/html");
  sent = sent;
}

void bootstrap()
{
  File file = SPIFFS.open("/bootstrap.min.css.gz", "r"); 
  size_t sent = server.streamFile(file, "text/css");
  sent = sent;
}

void bootstrapmin()
{
  File file = SPIFFS.open("/bootstrap.min.js.gz", "r"); 
  size_t sent = server.streamFile(file, "application/javascript");
  sent = sent;
}

void jquerymin()
{
  File file = SPIFFS.open("/jquery-3.4.1.min.js.gz", "r"); 
  size_t sent = server.streamFile(file, "application/javascript");
  sent = sent;
}


void setup() {
   Serial.begin(115200);
   
   WiFi.mode(WIFI_STA);
   WiFi.begin(ssid,password); 
   // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

server.begin(); 


server.on("/", fileindex);
server.on("/index.html", fileindex);
server.on("/bootstrap.min.css", bootstrap);
server.on("bootstrap.min.css", bootstrap);
server.on("/bootstrap.min.js", bootstrapmin);
server.on("bootstrap.min.js", bootstrapmin);
server.on("/jquery-3.4.1.min.js", jquerymin);
server.on("jquery-3.4.1.min.js", jquerymin);
server.on("/fonts/glyphicons-halflings-regular.woff", filefont1);
server.on("fonts/glyphicons-halflings-regular.woff", filefont1);

//NEW
SPIFFS.begin(); 


}

void loop() {
server.handleClient();


}
