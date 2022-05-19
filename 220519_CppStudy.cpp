#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void sub(int person, int pizza) {
	double d = 0;
	if (person < 1)
		throw person;
	if (pizza < 1)
		throw d;
}

// 예외처리
/*
int main(void) {
	int pizza_slices = 0;
	int persons = 0;
	int slice_per_person = 0;

	cout << "피자 조각수를 입력하시오 : ";
	cin >> pizza_slices;
	cout << "사람수를 입력하시오 : ";
	cin >> persons;

	try {
		if (persons == 0 || persons < 0)
			throw persons;
		slice_per_person = pizza_slices / persons;
		cout << "한 사람당 피자는 " << slice_per_person << "입니다." << endl;
	}
	catch (int e) {
		cout << "예외처리입니다." << endl;
		cout << "사람 숫자가 " << e << "명입니다.";
	}
	

	return 0;
}
*/

// 함수로 예외처리
// 사람 수와 피자 개수의 에러 처리를 위해 throw하는 값의 데이터형을 int형과 double형으로 나눔.
/*
int main(void) {
	int pizza_slices = 0;
	int persons = 0;
	int slice_per_person = 0;

	cout << "피자 조각수를 입력하시오 : ";
	cin >> pizza_slices;
	cout << "사람수를 입력하시오 : ";
	cin >> persons;

	try {
		sub(persons, pizza_slices);

		slice_per_person = pizza_slices / persons;
		cout << "한 사람당 피자는 " << slice_per_person << "입니다." << endl;
	}
	catch (int e) {
		cout << "예외처리입니다.(사람 숫자 예외처리)" << endl;
		cout << "사람 숫자가 " << persons << "명입니다.";
	}
	catch (double de) {
		cout << "예외처리입니다.(피자 개수 예외처리)" << endl;
		cout << "피자 개수가 " << pizza_slices << "개입니다.";
	}
	catch (...) {
		cout << "모든 에러 처리 발생" << endl;
	}

	return 0;
}
*/

// 예외처리
// 문자열 예외처리 매개변수 사용법
/*
int main(void) {
	int pizza_slices = 0;
	int persons = 0;
	int slice_per_person = 0;

	cout << "피자 조각수를 입력하시오 : ";
	cin >> pizza_slices;
	cout << "사람수를 입력하시오 : ";
	cin >> persons;

	try {
		if (persons < 0)
			throw "negative";
		else if (persons == 0)
			throw persons;

		slice_per_person = pizza_slices / persons;
		cout << "한 사람당 피자는 " << slice_per_person << "개 입니다." << endl;
	}
	//문자열의 매개변수는 const char* 형으로 처리해야 함.
	catch (const char* s) {
		cout << "예외처리" << endl;
		cout << s << endl;
	}
	catch (int e) {
		cout << "예외처리\n" << e << "명" << endl;
	}

	return 0;
}
*/

// 함수 템플릿
// 다양한 데이터형 값에 대한 처리가 가능해진다.
// 템플릿 함수에 오버로딩도 가능.
/*
template<typename T>
T add(T n1, T n2) {
	return n1 + n2;
}
template<typename T>
T add(T n1, T n2, T n3) {
	return n1 + n2 + n3;
}
template<typename T, typename U>
U add(T n1, U n2) {
	cout << "다른 typename" << endl;
	return n1 + n2;
}

int main(void) {
	int num1 = 10, num2 = 20;
	int sum = add(num1, num2);
	cout << "int sum = " << sum << endl;

	double num3 = 10.3, num4 = 20.5;
	double dsum = add(num3, num4);
	cout << "double sum = " << dsum << endl;

	int n1 = 11, n2 = 22, n3 = 33;
	int sumNum = add(n1, n2, n3);
	cout << "int sum = " << sumNum << endl;

	int num5 = 30;
	double num6 = 20.5;
	double dsum2 = add(num5, num6);
	cout << "sum = " << dsum2 << endl;

	return 0;
}
*/

// 클래스 템플릿
// 클래스 객체를 만들 때 여러 자료형으로 생성 가능
/*
template<typename T>
class Box {
private:
	int num;
	T data;

public:
	Box() {
		cout << "Box 생성자입니다." << endl;
	}

	void setBox(T data) {
		this->data = data;
	}

	T getBox() {
		return data;
	}
};

int main(void) {
	Box<int> b1;
	b1.setBox(100);
	cout << b1.getBox() << endl;

	Box<double> b2;
	b2.setBox(3.141592);
	cout << b2.getBox() << endl;

	return 0;
}
*/
