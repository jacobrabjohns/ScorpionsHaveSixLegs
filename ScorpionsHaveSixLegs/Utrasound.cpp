// 
// 
// 

#include "Arduino.h"
#include "Utrasound.h"

int UtrasoundClass::initCount = 0;
UtrasoundClass* UtrasoundClass::allVision[2] = {};

void UtrasoundClass::init(int tp, int ep)
{
	triggerPin = tp;
	echoPin = ep;

	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);

	UtrasoundClass::allVision[initCount] = this;
}

long UtrasoundClass::getRange()
{
	// Make sure the pin is in a clean low state (redundant but reduces jitter?)
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);

	// Set pin to high state for 10microseconds to begin ping 

	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);

	//Reset pin to low state
	digitalWrite(triggerPin, LOW);

	//Read the echo delay
	duration = pulseIn(echoPin, HIGH);

	// The speed of sound is 340 m/s or 29 microseconds per centimeter.
	// The ping travels out and back, so to find the distance of the object we
	// take half of the distance travelled.

	distance = duration / 29 / 2;

	printDistance(this, distance);
	return distance;
}

void UtrasoundClass::printDistance(UtrasoundClass* ref, long distance)
{
	if (ref == &LeftVision)
	{
		Serial.print("Left : ");
	}
	else {
		Serial.print("Right : ");
	}

	Serial.print(distance);
	Serial.print(" cm");
	Serial.println();
}

void UtrasoundClass::test()
{
	UtrasoundClass* current;
	for (size_t i = 0; i < 2; i++)
	{
		current = allVision[i];
		current -> getRange();
	}
}


UtrasoundClass LeftVision;
UtrasoundClass RightVision;


