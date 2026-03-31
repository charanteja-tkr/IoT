#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

const char ssid[] = "Anu";
const char pass[] = "123456789";

WiFiClient client;

unsigned long channelNumber = 2845211;
const char *readAPIKey = "DF7LO78W7FHP3668";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, pass);
    delay(5000);
  }

  long temp = ThingSpeak.readLongField(channelNumber, 1, readAPIKey);
  long humidity = ThingSpeak.readLongField(channelNumber, 2, readAPIKey);

  Serial.println(temp);
  Serial.println(humidity);

  delay(2000);
}