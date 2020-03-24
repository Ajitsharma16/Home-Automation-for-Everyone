#include <ESP8266WiFi.h>
#include "Adafruit_MQTT_Client.h"
#define wifi "CR7"
#define password "Aaravanya"
#define server "io.adafruit.com"
#define port 1883
#define username "Akeverywhere"
#define key "ef9702e3fc754a778d991e494e521b98"
WiFiClient esp;
Adafruit_MQTT_Client mqtt(&esp,server,1883,username,key);
Adafruit_MQTT_Subscribe feed = Adafruit_MQTT_Subscribe(&mqtt,username "/Feeds/LED 2");

void setup()
{
  Serial.begin(115200);
  delay(10);
  Serial.println("Adafruit MQTT ");
  Serial.println();
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(wifi);
  WiFi.begin(wifi, password);

  while(WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    }
    Serial.println();
    Serial.println("WiFi connected");
    Serial.println("IP address:");
    Serial.println(WiFi.localIP());
    
    mqtt.subscribe(&feed);

   Serial.println("connecting to MQTT");
   while(mqtt.connect())

   {
    delay (500);
    Serial.println(".");
   }
}
void loop()
{ 
  while(mqtt.readSubscription(5000))
{Serial.print("Got:");
 Serial.print((char *)feed.lastread);
 int a = atoi((char *)feed.lastread);
 Serial.print(" ");
 Serial.println(a);
 if (a==1)
{
  digitalWrite(16,HIGH);
}
else
{
  digitalWrite(16,LOW);
 } 
}
}
/*{
  Serial.print("Got:");
  Serial.print((char *)feed.lastread);
  int b = atoi((char *)feed.lastread);
  Serial.print(" ");
  Serial.println(b);
if (b==0)
{
  digitalWrite(5,LOW);
}
else
{
  digitalWrite(5,HIGH);
}
   }*/
 
