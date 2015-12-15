int i;

void setup(){
  pinMode(13,OUTPUT);
  pinMode(A4,INPUT);
}

void loop(){
  i = digitalRead(A4);
  if( i == HIGH ) digitalWrite(13,HIGH);
  else digitalWrite(13,LOW);
}

