#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//가상함수, 상향/하향 형변환
/*
class Animal {
private:
	string str = "사람";
	string str2 = "부모";

public:
	Animal() {
		cout << "사람 생성자" << endl;
	}

	virtual ~Animal() {
		cout << "사람 소멸자" << endl;
	}

	//virtual void speak() = 0;							//순수 가상 함수

	virtual void speak() {
		cout << str << endl;
	}

	void view() {
		cout << str2 << endl;
	}
};

class Dog : public Animal {
private:
	string str = "강아지";

public:
	Dog() {
		cout << "강아지 생성자" << endl;
	}
	~Dog() {
		cout << "강아지 소멸자" << endl;
	}

	void speak() {
		cout << str << endl;
	}
};

class Cat : public Animal {
private:
	string str = "고양이";

public:
	Cat() {
		cout << "고양이 생성자" << endl;
	}
	~Cat() {
		cout << "고양이 소멸자" << endl;
	}

	void speak() {
		cout << str << endl;
	}
};

int main(void) {
	
	Dog* d1 = new Dog();
	Cat* c1 = new Cat();

	d1->speak();
	c1->speak();
	

	//상향 형변환이 있어야 하향 형변환이 이루어짐.
	Animal* d1 = new Dog();					//상향 형변환
	Dog* d2 = (Dog*)d1;						//하향 형변환

	d1->speak();
	((Dog*)d1)->speak();					//자식 클래스(Dog)에 접근하여 speak 함수 호출
	((Dog*)d1)->view();						//상속받은 view 함수 호출
	d2->speak();

	delete d1;	
	

	
	Dog d;
	Animal& a1 = d;
	//= Animal *d1 = new Dog() <- 정적으로 들어가는 것.
	a1.speak();
	

	
	Animal* d1 = new Dog();
	Animal* c1 = new Cat();

	d1->speak();
	c1->speak();
	

	return 0;
}
*/

//추상 클래스와 상속 관계
/*
class Remote {
public:
	Remote() {

	}
	virtual ~Remote() {

	}

	//순수 가상 함수
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;


};

class Television : public Remote {
public:
	void turnOn() {
		cout << "텔레비전 On" << endl;
	}
	void turnOff() {
		cout << "텔레비전 Off" << endl;
	}

};

class Refrigerator : public Remote {
public:
	void turnOn() {
		cout << "냉장고 On" << endl;
	}
	void turnOff() {
		cout << "냉장고 Off" << endl;
	}
};

int main(void) {
	Remote* r1 = new Television();
	Remote* r2 = new Refrigerator();

	Television* t1 = (Television*)r1;
	t1->turnOff();
	((Television*)r1)->turnOff();

	r1->turnOn();
	r2->turnOff();

	delete r1;
	delete r2;

	return 0;
}
*/

//예제(이 코드 기반으로 과제)
/*
class AutoMachine {
private:
	int coin = 0;
	int calc = 0;
	int remain = 0;
	int cola = 1000;
	int cider = 800;
	int fanta = 1200;
	int twoPercent = 2000;

public:
	AutoMachine() {
		cout << "어서오세요, 자동판매기입니다." << endl;
	}

	void menu() {
		cout << "<메뉴>" << endl;
		cout << "1 : 콜라(1000)\n2 : 사이다(800)\n3 : 환타(1200)\n4 : 2%(2000)" << endl;
	}

	void setCoin(int coin) {
		if (coin > 0)
			this->coin = coin;
		else
			cout << "잔액이 부족합니다." << endl;
	}

	void setCoin() {
		cout << "돈을 넣으세요. : ";
		cin >> coin;

		if (coin > 0)
			this->coin = coin;
		else
			cout << "잔액이 부족합니다." << endl;
	}

	int getCoin() {
		return coin;
	}

	void setDrink(int drink) {
		if (drink == 1)
			coin -= 1000;
		else if (drink == 2)
			coin -= 800;
		else if (drink == 3)
			coin -= 1200;
		else
			coin -= 2000;
	}
};

int main(void) {
	int coin;
	AutoMachine am;

	am.menu();
	//1번째 경우
	cout << "돈을 넣으세요. : ";
	cin >> coin;
	am.setCoin(coin);
	//2번째 경우
	am.setCoin();
	cout << "투입된 금액 : " << am.getCoin() << endl;
	
	return 0;
}
*/