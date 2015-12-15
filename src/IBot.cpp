/*I-Bot.c - Electronic part driven for I-Bot' robot*/

#include "IBot.h"

volatile int en2[2];
char I_Motor::motor_count = 0;

I_Motor::I_Motor(int _in1,int _in2,int _en){
	in1 = _in1;
	in2 = _in2;
	motor_number = motor_count;
	pinMode(_in1,OUTPUT);
	pinMode(_in2,OUTPUT);
	pinMode(_en,OUTPUT);
	if(motor_count == 0){
		TCCR2A |= 0b00000011;
		TCCR2B |= 0b00000100;
		TIMSK2 |= 0b00000011;
		OCR2A = 0;
		en2[0] = _en;
		motor_count++;
	}
	else if(motor_count == 1){
		TCCR2A |= 0b00000011;
		TCCR2B |= 0b00000100;
		TIMSK2 |= 0b00000111;
		OCR2B = 0;
		motor_count++;
		en2[1] = _en;
	}
	else{
		#warning  ("fuck it exceed the Limit the number of motor bitch!");
	}
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
	
	if(motor_number == 0){
		OCR2A = num;
	}
	else if(motor_number == 1){
		OCR2B = num;
	}
}

void I_Motor::stop(){
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	if(motor_number == 0){
		OCR2A = 0;
	}
	else if(motor_number == 1){
		OCR2B = 0;
	}
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

//I_Motor::motor_count = 0;

ISR(TIMER2_COMPA_vect){
  digitalWrite(en2[0],LOW);
}

ISR(TIMER2_COMPB_vect){
  digitalWrite(en2[1],LOW);
}

ISR(TIMER2_OVF_vect){
  digitalWrite(en2[0],HIGH);
  digitalWrite(en2[1],HIGH);
}