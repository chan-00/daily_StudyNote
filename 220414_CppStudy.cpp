//220413_class ��� ���� ���� �ڵ�
#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Ŭ���� ��� ����
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

	//�ڽ� Ŭ�������� view �Լ� ������(�������̵�)
	void view() {
		Car::view();
		cout << "SportsCar ������ turbo = " << turbo << endl;
	}


	void show() {
		cout << "turbo = " << turbo << endl;
	}
};
*/

//Ŭ���� ���� ���
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
	//�������� �پ��� Ȱ��
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
	//������ view �Լ��� �ƴ� �θ� Ŭ������ view �Լ� ȣ��.
	s1.Car::view();
	*/

	//���� ���
	Truck t1;
	t1.view();
	t1.show();
	t1.contents();

	return 0;
}