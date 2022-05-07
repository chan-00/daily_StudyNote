#include<iostream>
#include "AutoSeller.h"

using std::cout;
using std::cin;
using std::endl;

int main(void) {
	int select;

	cout << "어떤 자판기를 선택하시겠습니까?" << endl;
	cout << "1. 커피 자판기\n2. 음료수 자판기\n3. 컵라면 자판기\n" << "=> ";
	cin >> select;

	if (select == 1) {
		CoffeeAutoSeller coffee;
		coffee.setDrink();
	}
	else if (select == 2) {
		DrinkAutoSeller drink;
		drink.setDrink();
	}
	else if (select == 3) {
		CupNoodlesAutoSeller cupNoodles;
		cupNoodles.setDrink();
	}
	else {
		cout << "메뉴를 잘못 입력했으므로 프로그램이 종료됩니다." << endl;
	}

	return 0;
}