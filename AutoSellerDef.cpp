//각 클래스의 소멸자들의 실질적 행동(동적할당 해제 등)은 없지만 소멸자의 호출 시점을 보기 위해 출력문을 썼습니다.
#include<iostream>
#include<cstring>
#include "AutoSeller.h"

using std::cout;
using std::cin;
using std::endl;


//AutoSeller 생성자
AutoSeller::AutoSeller():coin(0), remain(0), calc(0) {}

//설정자, 접근자 함수들 ~~~
void AutoSeller::setCoin(int coin) {
	if (coin > 0)
		this->coin += coin;
	else
		cout << "투입한 돈의 값이 정상적이지 않습니다." << endl;
}

int AutoSeller::getCoin() {
	return coin;
}

void AutoSeller::setRemain(int remain) {
	if (remain > 0)
		this->remain += remain;
	else if (remain < 0) {
		cout << "거스름돈이 음수가 되었습니다." << endl;
		this->remain += remain;
	}
	else
		cout << "입력된 거스름돈 값이 정상적이지 않습니다." << endl;
}

int AutoSeller::getRemain() {
	return remain;
}

void AutoSeller::setCalc(int calc) {
	if (calc >= 0)
		this->calc += calc;
	else if(calc < 0)
		cout << "입력된 계산값이 정상적이지 않습니다." << endl;
}

int AutoSeller::getCalc() {
	return calc;
}
//~~~ 설정자, 접근자 함수들

//멤버변수 0으로 초기화 해 주는 함수들 ~~~
void AutoSeller::resetCoin() {
	coin = 0;
}

void AutoSeller::resetRemain() {
	remain = 0;
}

void AutoSeller::resetCalc() {
	calc = 0;
}
//~~~

//AutoSeller 소멸자
AutoSeller::~AutoSeller() {
	cout << "자동판매기의 소멸자 호출입니다." << endl;
}


//CoffeeAutoSeller 생성자
CoffeeAutoSeller::CoffeeAutoSeller() {
	char coffeeMenu[5][20] = { "아메리카노", "카페라떼", "카푸치노", "카라멜 마끼아또", "카페모카" };
	int price[5] = { 1500, 1800, 2000, 2500, 2300 };

	for (int i = 0; i < 5; i++) {
		strcpy(menu[i], coffeeMenu[i]);
		menuPrice[i] = price[i];
	}
}

//커피 자판기의 메뉴를 보여주는 함수
void CoffeeAutoSeller::showMenu() {
	cout << "**************************************************" << endl;
	cout << "\t\t<커피 자판기>" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ". " << menu[i] << "(" << menuPrice[i] << "원)" << endl;
	}
	cout << "**************************************************" << endl;
}

//커피 자판기에서 사용자에게 입력을 받는 함수
void CoffeeAutoSeller::setDrink() {
	int selectMenu, menuCount, inputCoin;
	char prog;
	showMenu();

	while (true) {
		cout << "어떤 메뉴를 고르시겠습니까?" << endl << "=> ";
		cin >> selectMenu;
		cout << "몇 개를 선택하시겠습니까?" << endl << "=> ";
		cin >> menuCount;

		if (selectMenu >= 1 && selectMenu <= 5) {
			setCalc(menuPrice[selectMenu - 1] * menuCount);
		}
		else {
			cout << "메뉴를 잘못 입력했습니다." << endl;
		}

		cout << "계속 메뉴를 고르시겠습니까?(y, n) : ";
		cin >> prog;

		if (prog == 'y')
			cout << "계속 입력을 진행하겠습니다." << endl << endl;
		else
			break;
	}

	cout << endl << "돈을 넣어주세요 : ";
	cin >> inputCoin;
	setCoin(inputCoin);
	setRemain(getCoin() - getCalc());

	if (getRemain() > 0)
		cout << getRemain() << " 원 만큼의 거스름돈이 반환되었습니다." << endl;
	else
		cout << (getRemain() * -1) << " 원 만큼의 돈이 부족하여 커피가 나오지 않았습니다." << endl;

	resetCoin();
	resetRemain();
	resetCalc();
}

//CoffeeAutoSeller의 소멸자
CoffeeAutoSeller::~CoffeeAutoSeller() {
	cout << "커피 자판기의 소멸자 호출입니다." << endl;
}


//DrinkAutoSeller 생성자
DrinkAutoSeller::DrinkAutoSeller() {
	char drinkMenu[8][20] = { "환타", "코카콜라", "펩시", "코카콜라 제로", "펩시 제로", "미란다", "2%", "칠성사이다" };
	int price[8] = { 1000, 2000, 1500, 2500, 2000, 900, 2200, 1800 };

	for (int i = 0; i < 8; i++) {
		strcpy(menu[i], drinkMenu[i]);
		menuPrice[i] = price[i];
	}
}

//음료수 자판기의 메뉴를 보여주는 함수
void DrinkAutoSeller::showMenu() {
	cout << "**************************************************" << endl;
	cout << "\t\t<음료수 자판기>" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i + 1 << ". " << menu[i] << "(" << menuPrice[i] << "원)" << endl;
	}
	cout << "**************************************************" << endl;
}

//음료수 자판기에서 사용자에게 입력을 받는 함수
void DrinkAutoSeller::setDrink() {
	int selectMenu, menuCount, inputCoin;
	char prog;
	showMenu();

	while (true) {
		cout << "어떤 메뉴를 고르시겠습니까?" << endl << "=> ";
		cin >> selectMenu;
		cout << "몇 개를 선택하시겠습니까?" << endl << "=> ";
		cin >> menuCount;

		if (selectMenu >= 1 && selectMenu <= 8) {
			setCalc(menuPrice[selectMenu - 1] * menuCount);
		}
		else {
			cout << "메뉴를 잘못 입력했습니다." << endl;
		}

		cout << "계속 메뉴를 고르시겠습니까?(y, n) : ";
		cin >> prog;

		if (prog == 'y')
			cout << "계속 입력을 진행하겠습니다." << endl << endl;
		else
			break;
	}

	cout << endl << "돈을 넣어주세요 : ";
	cin >> inputCoin;
	setCoin(inputCoin);
	setRemain(getCoin() - getCalc());

	if (getRemain() > 0)
		cout << getRemain() << " 원 만큼의 거스름돈이 반환되었습니다." << endl;
	else
		cout << (getRemain() * -1) << " 원 만큼의 돈이 부족하여 음료수가 나오지 않았습니다." << endl;

	resetCoin();
	resetRemain();
	resetCalc();
}

//DrinkAutoSeller의 소멸자
DrinkAutoSeller::~DrinkAutoSeller() {
	cout << "음료수 자판기의 소멸자 호출입니다." << endl;
}


//CupNoodlesAutoSeller 생성자
CupNoodlesAutoSeller::CupNoodlesAutoSeller() {
	char noodlesMenu[7][20] = { "신라면", "진라면 매운맛", "진라면 순한맛", "오징어짬뽕", "불닭볶음면", "치즈볶이", "진짬뽕" };
	int price[7] = { 1500, 2000, 1500, 1700, 2000, 1000, 1400 };

	for (int i = 0; i < 7; i++) {
		strcpy(menu[i], noodlesMenu[i]);
		menuPrice[i] = price[i];
	}
}

//컵라면 자판기의 메뉴를 보여주는 함수
void CupNoodlesAutoSeller::showMenu() {
	cout << "**************************************************" << endl;
	cout << "\t\t<컵라면 자판기>" << endl;
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ". " << menu[i] << "(" << menuPrice[i] << "원)" << endl;
	}
	cout << "**************************************************" << endl;
}

//컵라면 자판기에서 사용자에게 입력을 받는 함수
void CupNoodlesAutoSeller::setDrink() {
	int selectMenu, menuCount, inputCoin;
	char prog;
	showMenu();

	while (true) {
		cout << "어떤 메뉴를 고르시겠습니까?" << endl << "=> ";
		cin >> selectMenu;
		cout << "몇 개를 선택하시겠습니까?" << endl << "=> ";
		cin >> menuCount;

		if (selectMenu >= 1 && selectMenu <= 7) {
			setCalc(menuPrice[selectMenu - 1] * menuCount);
		}
		else {
			cout << "메뉴를 잘못 입력했습니다." << endl;
		}

		cout << "계속 메뉴를 고르시겠습니까?(y, n) : ";
		cin >> prog;

		if (prog == 'y')
			cout << "계속 입력을 진행하겠습니다." << endl << endl;
		else
			break;
	}

	cout << endl << "돈을 넣어주세요 : ";
	cin >> inputCoin;
	setCoin(inputCoin);
	setRemain(getCoin() - getCalc());

	if (getRemain() > 0)
		cout << getRemain() << " 원 만큼의 거스름돈이 반환되었습니다." << endl;
	else
		cout << (getRemain() * -1) << " 원 만큼의 돈이 부족하여 컵라면이 나오지 않았습니다." << endl;

	resetCoin();
	resetRemain();
	resetCalc();
}

//CupNoodlesAutoSeller의 소멸자
CupNoodlesAutoSeller::~CupNoodlesAutoSeller() {
	cout << "컵라면 자판기의 소멸자 호출입니다." << endl;
}