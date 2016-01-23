#include<IBot.h>
I_Sensor sensor(5,A1,A2,A3,A4,A5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(sensor.read(0));
  Serial.print("\t,");
  Serial.print(sensor.read(1));
  Serial.print("\t,");
  Serial.print(sensor.read(2));
  Serial.print("\t,");
  Serial.print(sensor.read(3));
  Serial.print("\t,");
  Serial.println(sensor.read(4)); 
 
  delay(100); // delay 100 miliseconed
}
