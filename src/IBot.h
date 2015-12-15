/*I-Bot.h - Electronic part driven for I-Bot' robot*/

#ifndef Ibot_h
#define Ibot_h

#include "Arduino.h"

class I_Motor{
private:
	int in1;
	int in2;
	int en;
	
public:
	I_Motor(int _in1,int _in2,int _en);
	void speed(int num);
	void stop();
};

class I_Ultra_Sonic{
private:
	int trig;
	int echo;
	
public:
	I_Ultra_Sonic(int t,int e);
	long read_cm();
	long read_inch();
};

#endif