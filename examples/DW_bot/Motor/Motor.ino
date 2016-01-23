#include<IBot.h>

I_Motor L_motor(7,6,11);
I_Motor R_motor(8,9,10);
void setup(){
  
}

void loop(){
 
  R_motor.speed(200);
  delay(2000);
  R_motor.speed(0);
  delay(2000);
  R_motor.speed(-200);
  delay(2000);
  R_motor.speed(0);
  delay(2000);

}
