// Utrasound.h

#ifndef _UTRASOUND_h
#define _UTRASOUND_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class UtrasoundClass
{
public:
	void init(int tp, int ep);
	long getRange();

	static void test();

private:
	int triggerPin, echoPin;
	long duration, distance;

	static void printDistance(UtrasoundClass* ref, long distance);
	static UtrasoundClass* allVision[2];
	static int initCount;
};

extern UtrasoundClass LeftVision;
extern UtrasoundClass RightVision;

#endif

