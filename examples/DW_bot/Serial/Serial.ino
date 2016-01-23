#define SW1 A0
#define SW2 2
#define SW3 3

int i,j,k;

void setup() {
  k = 5;
  pinMode(SW1,INPUT_PULLUP);
  pinMode(SW2,INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("SOS");
}

void loop() {
  i = digitalRead(SW1); // Read logic from pin A0
  j = digitalRead(2); // Read logic from pin 2
  Serial.print("SW1 = ");
  Serial.println(i);
  delay(200);
}
