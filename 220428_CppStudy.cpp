#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//중단점 관련 코드
/*
int main(void) {
	int a = 10, b = 20;
	int c = 0;
	cout << "c = " << c << endl;			//초기화 과정이 잘 되었는지 확인

	cout << "c = " << c << endl;
	c = a + b;
	cout << "c = " << c << endl;			//값을 바구기 전과 후를 출력문(중단점)을 통해 확인
											//어느 구간에서 c값에 문제가 생겼는지 범위를 유추할 수 있게 됨.

	c = a + c;								//발견하지 못한 상황

	cout << "c = " << c << endl;			//c가 30이 나와야 하는데 40이 나옴.

	return 0;
}
*/

//f11 단축키와 f10 단축키의 차이점 확인하기
/*
int methodA(int a) {
	return a + 100;
}

int methodB() {
	return -200;
}

int methodC(int a, int b) {
	int c = 0;
	if (a < 0)
		a *= -1;
	c = a * 1000;

	return c;
}
//중단점을 찍고 한 단계씩 실행(f11)과 프로시저 단위 실행(f10)의 차이점 잘 파악하기!
int main(void) {
	int num1 = 7;								//중단점 찍기
	int num2 = methodA(num1);
	int num3 = methodB();
	int num4 = methodC(num2, num3);				//중단점 찍기(num4의 선언까지만 알 수 있음, num3까지는 값의 확인 가능)
	int num5 = methodC(num3, num2);

	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;
	cout << "num5 = " << num5 << endl;


	return 0;
}
*/

//중단점 조건 주기
/*
int main(void) {
	//int num[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int num[10] = { 0 };
	int* p;

	p = num;

	for (int i = 0; i < 10; i++) {		//중단점 찍기
		num[i] = i * 10;				//중단점 찍기(반복문 과정 확인, 중단점 조건 주기)
	}

	cout << num[4] << endl;				//중단점 찍기(f5로 중단점 사이를 넘어가면 위의 for문 과정을 볼 수 없음.)
	cout << *(p+1) << endl;


	return 0;
}
*/

//클래스에서의 중단점 찍기
/*
class Car {
private:
	int speed = 10;
	int gear = 3;

public:
	Car() {
		cout << "어서오세요 !" << endl;						//중단점
	}

	~Car() {
		cout << "안녕히 가세요 !" << endl;					//중단점
	}

	void setSpeed(int speed) {								//중단점
		this->speed = speed;								//중단점
	}

	void view() {
		cout << "speed = " << speed << endl;				//중단점
		cout << "gear = " << gear << endl;
	}

};

int main(void) {
	Car c1;
	c1.setSpeed(300);
	c1.view();

	return 0;
}
*/

//디버깅 시점에 따른 변수가 다르게 보이는 것과 관련된 예시
/*
//아래 main 함수에서의 중단점은 num1, num2 변수에 대한 정보가 보이지만 여기로 중단점이 넘어오게 되면 a, b 변수에 대한 정보만 보이게 된다.
void sub(int a, int b) {							//중단점
	int c = 0;										//중단점
	c = a + b;										//중단점
	cout << "c = " << c << endl;					//중단점
}

int main(void) {
	int num1 = 10;
	int num2 = 20;
	sub(10, 20);									//중단점(디버깅 창에는 현재 시점에서의 변수들만 보이게 됨.)
	cout << "프로그램 종료" << endl;

	return 0;
}
*/