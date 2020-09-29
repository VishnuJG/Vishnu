  int DO = 2;
int DA =A0;

int sensorVal=0;
void setup() {
  // put your setup code here, to run once:
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
Serial.begin(9600);
}

void loop() {
//Serial.print("Digital: ");
  //Serial.println(digitalRead(DO));  //Print the digital value
  // put your main code here, to run repeatedly:
sensorVal= analogRead(DA);
Serial.println(sensorVal);
//delay(100);

if(sensorVal>=40)
{
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  delay(100);
  digitalWrite(5,LOW);
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(100);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(100);
  digitalWrite(9,LOW);
}
else
{
  digitalWrite(6,LOW);digitalWrite(5,LOW);digitalWrite(8,LOW);digitalWrite(9,LOW);digitalWrite(7,LOW);
}
}
