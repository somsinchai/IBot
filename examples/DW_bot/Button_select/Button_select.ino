#define SW1 A0
#define SW2 2
#define SW3 3

int i,j;

void setup() {
  pinMode(5, OUTPUT);
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);
}

void loop() {
  
  do{
  i = digitalRead(SW1); // Read logic from pin A0
  j = digitalRead(SW2); // Read logic from pin 2
  }while(i == HIGH && j == HIGH);
  
  if(i == HIGH){ // first program
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(5,LOW);
    delay(500);
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(5,LOW);
  }
  else{ // seconed program
    digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(5,LOW); 
  }
}
