#include "Ultrasonic.h"


Ultrasonic::Ultrasonic(int trig_pin, int echo_pin)
{
	TrigPin = trig_pin;
	EchoPin = echo_pin;
}

Ultrasonic::~Ultrasonic()
{
}

long Ultrasonic::GetRange()
{
}

long Ultrasonic::Ping()
{
	return 0;
}
