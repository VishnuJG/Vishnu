int soundSensor=2;
int LED=3;
bool LEDStatus=false;
void setup() {
  
  pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);

}

void loop() {
  int SensorData=digitalRead(soundSensor); 
  
  if(SensorData==1){

    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LED,HIGH);
    }
    else{
        LEDStatus=false;
        digitalWrite(LED,LOW);
    }
  }

}
