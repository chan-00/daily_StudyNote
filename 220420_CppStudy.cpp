#include "220420_CppStudy.h"

using std::cout;
using std::cin;
using std::endl;

int Car::count = 0;

Car::Car() : speed(0), gear(0), color("red"), Max_Speed(100) {
	count++;
}

Car::Car(int s) : speed(s), gear(0), color("red"), Max_Speed(100) {
	count++;
}

Car::Car(int s, int g) : speed(s), gear(g), color("red"), Max_Speed(100) {
	count++;
}

Car::Car(int s, int g, string c) : speed(s), gear(g), color(c), Max_Speed(100) {
	count++;
}

Car::Car(const Car& c) : Max_Speed(100) {
	Car(c.speed, c.gear, c.color);
}

void Car::setSpeed(int s) {
	this->speed = s;
}

void Car::print() const {
	cout << "speed = " << speed << endl;
	cout << "gear = " << gear << endl;
	cout << "color = " << color << endl;
	cout << "Max_Speed = " << Max_Speed << endl;
	cout << "count = " << count << endl << endl;
}

Car::~Car() {
	cout << count << "번째 Car 객체의 소멸자가 호출되었습니다." << endl;
	cout << "speed : " << speed << endl;
	count--;
}

int main(void) {
	Car arr[4] = {
		Car(),
		Car(10),
		Car(20, 2),
		Car(30, 4, "gold")
	};

	for (int i = 0; i < 4; i++) {
		cout << "<Car " << i + 1 << "번째>" << endl;
		(arr + i)->print();
	}

	return 0;
}