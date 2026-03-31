#include <SoftwareSerial.h>

SoftwareSerial Bluetooth(9, 8);

int LED = 4;

void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Bluetooth.available()) {
    char data = Bluetooth.read();

    if (data == '1') digitalWrite(LED, HIGH);
    else if (data == '0') digitalWrite(LED, LOW);
  }
}