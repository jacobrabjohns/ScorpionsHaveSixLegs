/*
 Name:		ScorpionsHaveSixLegs.ino
 Created:	3/29/2018 5:47:16 PM
 Author:	Jake
*/

// the setup function runs once when you press reset or power the board
#include <Servo.h>

#include "Leg.h"
#include "Utrasound.h"

int leftDistance;
int rightDistance;

void setup() {
	LeftVision.init(12, 13);
	RightVision.init(14, 15);

	LeftFrontLeg.init(16, 17, 18);
	LeftMiddleLeg.init(19, 20, 21);
	LeftRearLeg.init(22, 23, 24);

	RightFrontLeg.init(25, 26, 27);
	RightMiddleLeg.init(28, 29, 30);
	RightRearLeg.init(31, 32, 33);
}

// the loop function runs over and over again until power down or reset
void loop() {
	UtrasoundClass::test();
	LegClass::warmUp();
}
