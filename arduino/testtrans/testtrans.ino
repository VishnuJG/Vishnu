#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int SentMessage[1]={000};
RF24 radio(9, 10); // CE, CSN
const uint64_t pipe=0xE6E6E6E6E6E6;

void setup(void){
radio.begin(); // Start the NRF24L01
radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
}
void loop(void)
{
  SentMessage[0]=111;
  radio.write(SentMessage,1);
  
}
