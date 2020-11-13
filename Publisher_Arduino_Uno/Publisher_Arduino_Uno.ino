#include <SoftwareSerial.h>
#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <WiFiEspUdp.h>
#include <PubSubClient.h>

#define led_r 2
#define led_y 3
#define led_g 4

WiFiEspClient espClient;
PubSubClient client(espClient);
SoftwareSerial soft(6,7);

void setup() {
  pinMode(led_r,OUTPUT);
  pinMode(led_y,OUTPUT);
  pinMode(led_g,OUTPUT);
  digitalWrite(led_r,LOW);
  digitalWrite(led_y,LOW);
  digitalWrite(led_g,LOW);
  
  Serial.begin(9600);
  soft.begin(9600);
  WiFi.init(&soft);
  digitalWrite(led_r,HIGH);
  connectWiFi();
  
  client.setServer( "47.103.42.227", 1883 );
  connectMQTT();
}

void loop() {
  checkConnection();
  getAndSendData();
  delay(1000);
}

void getAndSendData()
{
  client.publish( "test", "hello" );
}

void checkConnection(){
  if ( WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }
  if ( !client.connected() ) {
    connectMQTT();
  }
}

void connectWiFi()
{
  while ( WiFi.status() != WL_CONNECTED) {
    digitalWrite(led_y,LOW);
    WiFi.begin("LeslieLiu_Mobile", "12345678");
    delay(500);
  }
  digitalWrite(led_y,HIGH);
}

void connectMQTT() {
  digitalWrite(led_g,LOW);
  while (!client.connected()) {
    client.connect("test");
    delay(500);
  }
  digitalWrite(led_g,HIGH);
}
