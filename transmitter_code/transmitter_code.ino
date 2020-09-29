/*
433MHz Transmitter Code
https://circuits4you.com
Transmitter is connected on PIN 12
 
 Arduino                     Transmitter
  GND--------------------------GND
  D12--------------------------Data
  5V---------------------------VCC
 
*/
 
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif
#include<stdio.h>
#define echoPin 9 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 10 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

 RH_ASK driver(2000, 4, 2, 5); // ESP8266: do not use pin 11
 
void setup()
{
    Serial.begin(9600);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
    //Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
    //Serial.println("with Arduino UNO R3");
}
 
void loop()
{
    distance=0;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (to and fro)
    const char *msg = "hello";int n=distance;int len=0;
    Serial.println(distance);
    while(n!=0)
    {
      n=n/10;
      len++;
    }
    if(distance<10 && distance!=0)
  {
    Serial.println("Hello");
    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
  }
  delay(200);
}
