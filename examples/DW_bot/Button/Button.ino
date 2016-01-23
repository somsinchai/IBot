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
  i = digitalRead(SW1); // Read logic from pin A0
  j = digitalRead(2); // Read logic from pin 2
  if(i == HIGH) digitalWrite(5,LOW);
  else digitalWrite(5,HIGH);
}
