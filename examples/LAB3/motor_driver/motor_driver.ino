#include<IBot.h>

I_Motor mymotor(12,13,11);
void setup(){
  
}

void loop(){
 
  mymotor.speed(200);
  delay(2000);
  mymotor.speed(0);
  delay(2000);
  mymotor.speed(-200);
  delay(2000);
  mymotor.speed(0);
  delay(2000);

}
