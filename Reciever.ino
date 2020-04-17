#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
int ledPin=2;
RF24 radio(7, 8);
const byte address[6] = "00001";
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);  
  }
}
