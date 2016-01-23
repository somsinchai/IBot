#include<IBot.h>
int tmp;
I_Ultra_Sonic mysensor(13,12);

void setup(){
  Serial.begin(9600);
}
void loop(){
  tmp = mysensor.read_cm();
  Serial.println(tmp);
  delay(250);
}
