#include<IBot.h>
I_Motor L_Motor(12,13,11);
I_Motor R_Motor(6,7,5);
I_Sensor MySensor(3,A3,A4,A5);

void setup(){

}

void loop(){
 
  if(analogRead(A3) == 0) L_Motor.speed(100);
  else L_Motor.speed(0);

  if(analogRead(A5) == 0) R_Motor.speed(100);
  else R_Motor.speed(0);

  delay(1);

}
