void setup() {
  pinMode(5, OUTPUT); // Set laser's pin (5) to output
}

void loop() {
  digitalWrite(5, HIGH); // Set laser's pin (5) to HIGH(true) logic
  delay(1000); // delay 1 seconed
  digitalWrite(5, LOW); // Set laser's pin (5) to LOW(false) logic
  delay(1000); // delay 1 seconed
}
