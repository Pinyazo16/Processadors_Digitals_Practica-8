#include <Arduino.h>
#include <HardwareSerial.h>

#define RXD0 3
#define TXD0 1
#define RXD2 16
#define TXD2 17

HardwareSerial SerialUART0(0);
HardwareSerial SerialUART2(2);

void setup() {
  Serial.begin(115200);
  SerialUART2.begin(115200, SERIAL_8E1, RXD2, TXD2);
}

void loop() {
  if(Serial.available()){
    char data = Serial.read();
    SerialUART2.write(data);
  }

  if(SerialUART2.available()){
    char data = SerialUART2.read();
    Serial.write(data);
  }
}