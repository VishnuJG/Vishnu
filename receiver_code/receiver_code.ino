/* 
 RF433Mhz Receiver Code
 https://circuits4you.com
 Receiver is connected on PIN 11
 
 Arduino                     Receiver
  GND--------------------------GND
  D11--------------------------Data
  5V---------------------------VCC
*/
 
#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
 
//RH_ASK driver;
RH_ASK driver(2000, 2, 9, 10); // ESP8266: do not use pin 11
 
void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
 
void loop()
{
    
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
 
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      int i;
      String str="";
      for(int i=0;i<buflen;i++)
      {
        str+=(char)buf[i];
      }
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
  // Message with a good checksum received, dump it.
  //driver.printBuffer("Got:", buf, buflen);
        // Use this in case hex values are displayed
          //Serial.print("Received:");
          //for (i = 0; i < buflen; i++) Serial.print(buf[i]);
          Serial.println(str);
        
     }
}
