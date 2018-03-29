// Leg.h

#ifndef _LEG_h
#define _LEG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Servo.h>

class LegClass
{
 public:
	void init(int hipPin, int coxaPin, int kneePin);
	void flex();
	void rotateHip(int degrees, int shouldWait), rotateCoxa(int degrees, int shouldWait), rotateKnee(int degrees, int shouldWait);

	static LegClass* allLegs[6];
	static void warmUp();

private:
	Servo hipServo;
	Servo coxaServo;
	Servo kneeServo;

	static int calculateDelay(int degrees);
	static int initCount;
};

extern LegClass LeftFrontLeg;
extern LegClass LeftMiddleLeg;
extern LegClass LeftRearLeg;

extern LegClass RightFrontLeg;
extern LegClass RightMiddleLeg;
extern LegClass RightRearLeg;

#endif

