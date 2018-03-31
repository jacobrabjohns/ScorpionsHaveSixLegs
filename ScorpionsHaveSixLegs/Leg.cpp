// 
// 
// 

#include "Leg.h"
int LegClass::initCount = 0;
LegClass* LegClass::allLegs[6] = {};

void LegClass::init(int hipPin, int coxaPin, int kneePin)
{
	hipServo.attach(hipPin);
	coxaServo.attach(coxaPin);
	kneeServo.attach(kneePin);

	allLegs[initCount] = this;
	initCount++;
}

void LegClass::flex()
{
	// The servo library se
	rotateHip(120, 1);
	rotateHip(60, 1);
	rotateHip(90, 1);

	rotateCoxa(120, 1);
	rotateCoxa(60, 1);
	rotateCoxa(90, 1);

	rotateKnee(120, 1);
	rotateKnee(60, 1);
	rotateKnee(90, 1);
}

void LegClass::rotateHip(int degrees, int shouldWait)
{
	hipServo.write(degrees);
	if (shouldWait)
	{
		delay(calculateDelay(degrees));
	}
}

void LegClass::rotateCoxa(int degrees, int shouldWait)
{
	coxaServo.write(degrees);
	if (shouldWait)
	{
		delay(calculateDelay(degrees));
	}
}

void LegClass::rotateKnee(int degrees, int shouldWait)
{
	kneeServo.write(degrees);
	if (shouldWait)
	{
		delay(calculateDelay(degrees));
	}
}

void LegClass::warmUp()
{
	LegClass* current;
	for (size_t i = 0; i < 6; i++)
	{
		current = allLegs[i];
		current -> flex();
	}
}

int LegClass::calculateDelay(int degrees)
{
	return degrees * 2; // Specs say the servo's move 60 degrees in 120 milliseconds
}


LegClass LeftFrontLeg;
LegClass LeftMiddleLeg;
LegClass LeftRearLeg;

LegClass RightFrontLeg;
LegClass RightMiddleLeg;
LegClass RightRearLeg;