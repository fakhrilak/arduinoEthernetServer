#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
byte ip[] = { 192,168,10,135 };    
EthernetServer server(80);
void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  pinMode(A0,INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  server.begin();
  Serial.println(Ethernet.localIP());
}

void loop()
{
  EthernetClient client = server.available();
  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<H1>WELCOME ARDUINO WEB SERVER</H1>");
    client.print("<button ><a href='https://twitter.com/fakhrilak/'>Go to Twitter</a></button>");
    client.println("<button ><a href='https://instagram.com/fakhrilak/'>Go to Instagram</a></button>");
    client.println("<button ><a href='https://github.com/fakhrilak/arduinoEthernetServer/'>Go to Code</a></button>");
    client.println("<img src='https://cdn.platformio.org/images/platformio-logo.17fdc3bc.png'/>");
    client.println("<h3 class={{color:red}}>Support by platform IO : <a href='https://platformio.org/'>www.platformio.org</a></h3>");
    client.println("<H1>SELAMAT MENCOBA.....</H1>");
    client.println("<style type='text/css'>h1{color:blue;text-align: left;} button{background-color: #4CAF50;border-radius:3px;margin:10px;width:'100%';height:20px,color:white}</style>");
    client.println("<br />");
    client.println("<br />");
    client.println("</html>");
    client.stop();
  }
}
