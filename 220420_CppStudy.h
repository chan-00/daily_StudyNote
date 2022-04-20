#ifndef __source__
#define __source__

#include<iostream>

using std::string;

class Car {
private:
	int speed;
	int gear;
	string color;
	const int Max_Speed;
	static int count;

public:
	Car();
	Car(int s);
	Car(int s, int g);
	Car(int s, int g, string c);
	Car(const Car& c);

	void setSpeed(int s);
	int getSpeed();
	void print() const;
	~Car();
};


#endif