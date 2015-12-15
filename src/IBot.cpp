/*I-Bot.c - Electronic part driven for I-Bot' robot*/

#include "IBot.h"

I_Motor::I_Motor(int _in1,int _in2,int _en){
	in1 = _in1;
	in2 = _in2;
	en = _en;
	pinMode(in1,OUTPUT);
	pinMode(in2,OUTPUT);
	pinMode(en,OUTPUT);
}

void I_Motor::speed(int num){
	if(num > 0){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);	
	}
	else if(num < 0){
	digitalWrite(in1,LOW);
	digitalWrite(in2,HIGH);
	num = -num;
	}
	else{
	digitalWrite(in1,LOW);
	digitalWrite(in2,HIGH);
	num = 0;
	}
	if(num > 255) num = 255;
	analogWrite(en,num);
}

void I_Motor::stop(){
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	analogWrite(en,255);
}

I_Ultra_Sonic::I_Ultra_Sonic(int t,int e){
	trig = t;
	echo = e;
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
	
}

long I_Ultra_Sonic::read_cm(){
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(5);
	digitalWrite(trig, LOW);
	return pulseIn(echo, HIGH) / 29 / 2;
}

long I_Ultra_Sonic::read_inch(){
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(5);
	digitalWrite(trig, LOW);
	return pulseIn(echo, HIGH) / 74 / 2;
}