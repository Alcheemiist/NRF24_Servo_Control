#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo myServo;
int val = 0;
 
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() 
{
  Serial.begin(9600);
  myServo.attach(3);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() 
{   
  if (radio.available()) 
  {
    val = 0;
    radio.read(&val, sizeof(val));
  }
  Serial.print("Value: ");
  Serial.println(val);
  myServo.write(val);
  delay(15);
}
