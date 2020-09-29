int audio=A0;
void setup() {
  // put your setup code here, to run once:
pinMode(audio, INPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
Serial.println("Listening");
}

void loop() {
  // put your main code here, to run repeatedly:
  int audio_input = analogRead(audio);
  Serial.println(audio_input);
  if(audio_input>50)
  {
    digitalWrite(5,HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(5,LOW);
  }
  if(audio_input>100)
  {
    digitalWrite(6,HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(6,LOW);
  }
  if(audio_input>200)
  {
    digitalWrite(7,HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(7,LOW);
  }
  if(audio_input>300)
  {
    digitalWrite(8,HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(8,LOW);
  }
  if(audio_input>400)
  {
    digitalWrite(9,HIGH);
    delay(50);
  }
  else
  {
    digitalWrite(9,LOW);
  }

}
