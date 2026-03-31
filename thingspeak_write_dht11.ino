#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include "DHT.h"

#define DHTPIN D4
#define DHTTYPE DHT11

char ssid[] = "YOUR_SSID";
char pass[] = "YOUR_PASS";

WiFiClient client;

unsigned long channelNumber = YOUR_CHANNEL_ID;
const char *writeAPIKey = "YOUR_API_KEY";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  dht.begin();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, pass);
    delay(5000);
  }

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);

  ThingSpeak.writeFields(channelNumber, writeAPIKey);

  delay(20000);
}