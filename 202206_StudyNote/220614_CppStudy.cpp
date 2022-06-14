﻿#include<iostream>
using namespace std;

//----------------------------이론----------------------------
//상속
/*
상속은 기존에 존재하는 유사 클래스로부터 속성/동작을 이어받고 자신이 필요한 기능을 추가하는 기법
-> 기존 클래스의 필드와 메소드 재사용, 신뢰성 있는 소프트웨어 손쉽게 개발, 유지 보수
, 코드의 중복을 줄일 수 있음.

단어 알아두기
슈퍼(, 부모, 베이스) 클래스 -> 서브(, 자식, 파생된) 클래스

UML에서의 표기법
private는 -, protected는 #, public은 +
화살표로 상속 관계 표시

상속은 is-a 관계(has-a(포함) 관계는 상속X)
~는 ~다(~는 ~를 갖고있다 와 같은 has-a는 X)

- 오버로딩
같은 함수명으로 매개변수의 형태(매개변수의 개수 혹은 데이터형)로 구분하여 여러 형태의
함수 제작 가능(단, 함수의 반환형은 오버로딩의 판단 기준X)

- 오버라이딩
자식 클래스에서 필요에 따라 상속받은 멤버 함수를 다시 정의하는 것.
(오버라이딩은 재정의할 부모 클래스의 멤버 함수와 형태가 완전히 동일해야 한다.)
(즉, 멤버 함수의 이름과 반환형, 매개변수의 개수와 데이터형 모두 일치해야 한다.)

재정의된 멤버 함수가 있을 시 호출 순서는 자식 클래스의 함수가 우선된다.

부모 클래스를 2개 이상 상속받으면 다중 상속이 된다.(이 경우 모호성 문제가 생길 수 있음)
*/

//다형성과 가상함수
/*
- 다형성?
객체들의 타입이 다르면 똑같은 메시지가 전달되더라도 서로 다른 동작을 하는 것

- 동적 바인딩과 정적 바인딩
정적 바인딩은 컴파일 단계에서 모든 바인딩이 완료되는 것
동적 바인딩은 바인딩이 실행 시까지 연기, 실행 시간에 실제 호출되는 함수를 결정하는 것이다.

- 추상 클래스
클래스에 완전 가상 함수가 하나라도 들어가면 추상 클래스라고 한다.
*/

//STL
/*
- STL의 3가지 구성 요소
1) 컨테이너
자료를 저장하는 구조(벡터, 리스트, 맵, 집합 등이 여기에 해당됨)
2) 반복자(iterator)
컨테이너 안의 요소들을 순차적으로 처리하기 위한 컴포넌트
3) 알고리즘
정렬, 탐색과 같은 다양한 알고리즘을 구현

- 순차 컨테이너
자료를 순차적으로 저장, (벡터, 데크, 리스트) 등이 있다.

- 연관 컨테이너
사전과 같은 구조를 사용하여 자료 저장, 자료들은 자동 정렬된다.
집합, 맵 등이 있음

- 컨테이너 어댑터
순차 컨테이너에 제약을 걸어 데이터들이 정해진 방식으로만 입출력
스택, 큐 등이 있음

- 람다식
ex) [](int x, int y) { return x + y; }
[] -> 람다 연산자, (int x, int y) -> 함수 매개 변수, { return x + y; } -> 함수 몸체
*/

//파일 입출력
/*
- ofstream(출력 파일 스트림 클래스, 출력 파일 생성하고 파일에 데이터를 쓸 때 사용)
- ifstream(입력 파일 스트림 클래스, 파일에서 데이터를 불러와 읽을 때 사용)
*/

//예외처리와 템플릿
/*
- 예외처리(try ~ catch)
try 블록의 코드는 예외가 발생할 수 있는 위험한 코드로, 예외가 발생할 상황에 throw를
던지면 해당 데이터형에 맞는 catch 블록의 코드로 가서 예외를 처리하게 된다.

- 예외가 던져졌을 때(throw) 첫 번째로 일치되는 예외를 선택하며 catch(...) 블록은
구체적인 예외 상황을 제외한 모든 예외를 처리하는 블록을 말한다.

- throw가 발생했을 때 해당 블록에서의 throw 밑 코드들은 실행되지 않고 바로 해당되는
catch문 블록 코드로 가게 된다.

- 사용자 정의 함수에서도 throw를 던질 수 있다.

- 구체적인 예외를 먼저 잡는다.
(만약 int형 catch문과 catch(...) 문이 있을 때 int 데이터형의 throw가 걸리면 int형의
catch문의 코드가 실행된다.)

- 클래스 템플릿 사용 시에는 클래스<데이터형> 객체 와 같이 데이터형을 명시해 줘야 한다.
*/
//----------------------------이론----------------------------






//----------------------------코딩----------------------------
//상향, 하향 형변환 예제
/*
class Animal {
private:
	string animal;
public:
	Animal() {
		cout << "Animal() 기본 생성자입니다." << endl;
		animal = "normal";
	}
	Animal(string str) : animal(str) {
		cout << "Animal(string) 생성자입니다." << endl;
	}

	void setAnimal(string animal) {
		this->animal = animal;
	}

	void Print() {
		cout << "animal : " << animal << endl;
	}

	virtual ~Animal() {
		cout << "Animal 소멸자입니다." << endl;
	}
};

class Dog: public Animal {
private:
	string dog;
public:
	Dog() {
		cout << "Dog 기본 생성자입니다." << endl;
	}
	Dog(string animal, string dog) : Animal(animal) {
		cout << "Dog(string) 생성자입니다." << endl;
		this->dog = dog;
	}

	void setDog(string dog) {
		this->dog = dog;
	}

	void Print() {
		cout << "dog : " << dog << endl;
	}

	~Dog() {
		cout << "Dog 소멸자입니다." << endl;
	}
};

int main(void) {
	Animal* ani = new Dog("dog", "poodle");
	Dog* d = (Dog*)ani;

	ani->Print();
	d->Print();
	d->setAnimal("Cat");
	d->setDog("false");

	ani->Print();
	((Dog*)ani)->Print();

	delete ani;

	return 0;
}
*/
//----------------------------코딩----------------------------