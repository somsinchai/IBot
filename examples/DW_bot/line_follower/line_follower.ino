#include<IBot.h>
I_Sensor sensor(5,A1,A2,A3,A4,A5);
I_Motor L_motor(7,6,11);
I_Motor R_motor(8,9,10);

int i,j;

void setup() {
  Serial.begin(9600);
}

void loop() {
  i = sensor.read(0);
  j = sensor.read(4); 
  
  if(i > 500) R_motor.speed(200);
  else R_motor.speed(0);
  if(j > 500) L_motor.speed(200);
  else L_motor.speed(0);
  
  delay(50); // delay for characteristic
}
