#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <DHT.h>

const char* ssid = "Anu";
const char* password = "123456789";

const char* udpAddress = "192.168.0.7";
const int udpPort = 8081;

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }

  Serial.println("WiFi connected.");
  dht.begin();
}

void loop() {
  delay(2000);

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) return;

  udp.beginPacket(udpAddress, udpPort);
  udp.print("Temperature: ");
  udp.print(t);
  udp.print(" °C, Humidity: ");
  udp.print(h);
  udp.println(" %");
  udp.endPacket();
}