#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

#define sens A0
int val = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(sens, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() 
{
  val = analogRead(sens);
  val = map(val, 0, 1023, 0, 180);
  Serial.println(val);
  radio.write(&val, sizeof(val));
  delay(5);
}
