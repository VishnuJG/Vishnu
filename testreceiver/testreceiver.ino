#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int ReceivedMessage[1] = {000};
RF24 radio(9,10);
const uint64_t pipe = 0xE6E6E6E6E6E6;
void setup(void){
radio.begin(); // Start the NRF24L01

radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive

radio.startListening();
}

void loop(void)
{
  Serial.println("Yrr");
  radio.read(ReceivedMessage,1);
  if (ReceivedMessage[0] == 111) // Indicates switch is pressed
  {
    Serial.println("Hello there");
  }
  else
  {
    Serial.println("Not so hello there");
  }
  delay(1000);
}
