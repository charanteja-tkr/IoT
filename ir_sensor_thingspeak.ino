#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

char ssid[] = "YOUR_SSID";
char pass[] = "YOUR_PASS";

WiFiClient client;

unsigned long channelNumber = YOUR_CHANNEL_ID;
const char *writeAPIKey = "YOUR_API_KEY";

const int irPin = D4;

void setup() {
  Serial.begin(115200);
  pinMode(irPin, INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  int value = digitalRead(irPin);

  ThingSpeak.writeField(channelNumber, 1, value, writeAPIKey);

  delay(20000);
}