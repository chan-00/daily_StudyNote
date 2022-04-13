//220413_class 상속 관련 공부 코드
#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//클래스 상속 관계
/*
class Car {
private:
	int speed = 100;
	int gear = 3;
	int turbo = 100;

public:
	Car() {

	}

	Car(int speed, int gear) {
		this->speed = speed;
		this->gear = gear;
	}

	~Car() {

	}

	void view() {
		cout << "speed = " << speed << endl;
		cout << "gear = " << gear << endl;
		cout << "turbo = " << turbo << endl;
	}
};
*/
/*
class SportCar: public Car {
private:
	int turbo = 300;

public:
	SportCar() {

	}

	SportCar(int turbo) {
		this->turbo = turbo;
	}

	SportCar(int s, int g):Car(s, g) {

	}

	SportCar(int s, int g, int turbo) :Car(s, g) {
		this->turbo = turbo;
	}

	~SportCar() {

	}

	//자식 클래스에서 view 함수 재정의(오버라이딩)
	void view() {
		Car::view();
		cout << "SportsCar 재정의 turbo = " << turbo << endl;
	}


	void show() {
		cout << "turbo = " << turbo << endl;
	}
};
*/

//클래스 다중 상속
class Car1 {
private:
	int speed = 200;
	int gear = 50;

public:
	void show() {
		cout << "speed = " << speed << endl;
		cout << "gear = " << gear << endl;
	}
};

class Car2 {
private:
	int speed = 100;
	int gear = 3;

public:
	void view() {
		cout << "speed = " << speed << endl;
		cout << "gear = " << gear << endl;
	}
};

class Truck : public Car1, public Car2 {
	int box = 5000;

public:
	void contents() {
		cout << "box = " << box << endl;
	}
};

int main(void) {
	//생성자의 다양한 활용
	/*
	SportCar s1(15);
	SportCar s2(200, 5);
	SportCar s3(200, 5, 100);

	s1.view();
	s1.show();

	s2.view();
	s2.show();

	s3.view();
	s3.show();
	*/

	/*
	SportCar s1;
	s1.view();
	s1.show();
	//재정의 view 함수가 아닌 부모 클래스의 view 함수 호출.
	s1.Car::view();
	*/

	//다중 상속
	Truck t1;
	t1.view();
	t1.show();
	t1.contents();

	return 0;
}