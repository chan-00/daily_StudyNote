#ifndef __AutoSell__
#define __AutoSell__

//자동판매기 부모 클래스
class AutoSeller {
private:
	int coin;									//사용자가 투입한 돈
	int remain;									//거스름돈 계산
	int calc;									//사용자가 주문한 만큼 넣어야 할 돈

public:
	//생성자
	AutoSeller();

	//설정자&접근자 함수
	void setCoin(int coin);
	int getCoin();
	void setRemain(int remain);
	int getRemain();
	void setCalc(int calc);
	int getCalc();

	//가상 함수
	virtual void showMenu() = 0;				//메뉴를 보여주는 함수
	virtual void setDrink() = 0;				//사용자가 메뉴를 고르고 돈을 투입했을 때 계산하는 함수

	//멤버변수 초기화하는 함수
	//설정자에서 기존 멤버변수에서 값을 더해주는 형식이기 때문에 필요에 따라 멤버변수의 값을 0으로 초기화 해 주는 함수가 필요할 수 있어 선언하였습니다.
	void resetCoin();
	void resetRemain();
	void resetCalc();

	//소멸자
	virtual ~AutoSeller();
};

//자동판매기 자식 클래스(커피 자판기)
class CoffeeAutoSeller : public AutoSeller {
private:
	char menu[5][20];							//메뉴 문자열이 저장되어 있는 배열
	int menuPrice[5];							//메뉴의 가격 값들이 저장되어 있는 배열

public:
	//생성자
	CoffeeAutoSeller();

	void showMenu();							//메뉴를 보여주는 함수(재정의)
	void setDrink();							//사용자가 메뉴를 고르고 돈을 투입했을 때 계산하는 함수(재정의)

	//소멸자
	~CoffeeAutoSeller();
};

//자동판매기 자식 클래스(음료수 자판기)
class DrinkAutoSeller : public AutoSeller {
private:
	char menu[8][20];							//메뉴 문자열이 저장되어 있는 배열
	int menuPrice[8];							//메뉴의 가격 값들이 저장되어 있는 배열

public:
	//생성자
	DrinkAutoSeller();

	void showMenu();							//메뉴를 보여주는 함수(재정의)
	void setDrink();							//사용자가 메뉴를 고르고 돈을 투입했을 때 계산하는 함수(재정의)

	//소멸자
	~DrinkAutoSeller();
};

//자동판매기 자식 클래스(컵라면 자판기)
class CupNoodlesAutoSeller : public AutoSeller {
private:
	char menu[7][20];							//메뉴 문자열이 저장되어 있는 배열
	int menuPrice[7];							//메뉴의 가격 값들이 저장되어 있는 배열

public:
	//생성자
	CupNoodlesAutoSeller();

	void showMenu();							//메뉴를 보여주는 함수(재정의)
	void setDrink();							//사용자가 메뉴를 고르고 돈을 투입했을 때 계산하는 함수(재정의)

	//소멸자
	~CupNoodlesAutoSeller();
};

#endif