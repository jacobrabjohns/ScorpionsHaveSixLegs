#pragma once
class Ultrasonic
{
public:
	Ultrasonic(int trig_pin, int echo_pin);
	long GetRange();
	~Ultrasonic();

private:
	int TrigPin;
	int EchoPin;
	long duration, distance;

	long Ping();
};


