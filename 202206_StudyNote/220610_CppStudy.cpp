#include<iostream>
#include<time.h>
#include<vector>
#include<list>
#include<deque>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

//상속 예제
/*
class Car {
private:
	int speed;
	int gear;
	int color;
public:
	Car(): speed(0), gear(0), color(0) {
		cout << "부모 Car 클래스 생성자 호출" << endl;
	}

	Car(int cspeed, int cgear, int ccolor) :
		speed(cspeed), gear(cgear), color(ccolor) {
		cout << "부모 Car 클래스 생성자 호출" << endl;
	}

	void setGear(int gear) {
		this->gear = gear;
	}

	void speedUp() {
		if (speed >= 100) {
			cout << "최대 속도는 100으로 제한됩니다." << endl;
		}
		else {
			speed += 10;
		}
	}

	void speedDown() {
		if (speed <= 0) {
			cout << "최저 속도는 0으로 제한됩니다." << endl;
		}
		else {
			speed -= 10;
		}
	}

	void Print() {
		cout << "speed = " << speed << endl;
		cout << "gear = " << gear << endl;
		cout << "color = " << color << endl;
	}
};

class SportsCar : public Car {
private:
	bool turbo;
public:
	SportsCar(bool cturbo): turbo(cturbo) {
		cout << "자식 SportsCar 생성자 호출" << endl;
	}

	void setTurbo(bool turbo) {
		this->turbo = turbo;
	}

	void Print() {
		cout << "turbo = " << turbo << endl;
	}
};

int main(void) {
	SportsCar sc(true);
	((Car)sc).Print();

	return 0;
}
*/

//상향/하향 형변환 예제
/*
class Shape {
protected:
	int x, y;
public:
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void draw() {
		cout << "Shape Draw" << endl;
	}
	void printOrigin() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
};

class Rectangle : public Shape {
private:
	int width, height;
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}
	void draw() {
		cout << "Rectangle Draw";
	}
};

class Circle : public Shape {
private:
	int radius;
public:
	void setRadius(int r) {
		radius = r;
	}
	void draw() {
		cout << "Circle Draw" << endl;
	}
};

int main(void) {
	Shape* ps = new Rectangle();
	ps->setOrigin(10, 10);
	ps->draw();
	ps->printOrigin();

	Rectangle* pr = (Rectangle*)ps;
	pr->setOrigin(20, 20);
	pr->draw();
	ps->printOrigin();

	return 0;
}
*/

//STL 예제(list)
/*
int main(void) {
	list<int> values;
	list<int>::iterator it;
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		values.push_back(rand() % 100);
	}
	values.sort();

	for (it = values.begin(); it != values.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
*/

//STL 예제(vector)
/*
int main(void) {
	vector<double> values;
	vector<double>::iterator it;
	double score;

	while (true) {
		cout << "학생의 성적을 입력하세요(음수 입력시 종료) : ";
		cin >> score;
		if (score < 0.0) break;
		values.push_back(score);
	}

	double high = values[0];

	for (it = values.begin(); it != values.end(); it++) {
		if (high < *it)
			high = *it;
	}
	cout << "학생 점수 중 최고점은 " << high << "점 입니다." << endl;

	return 0;
}
*/

//STL 예제(vector)02
/*
int main(void) {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (auto& n : v) {
		cout << n << " ";
	}
	cout << endl;
}
*/

//STL 예제(set)
/*
int main(void) {
	set<int> my_set;

	my_set.insert(1);
	my_set.insert(2);
	my_set.insert(3);

	auto pos = my_set.find(3);
	if (pos != my_set.end())
		cout << "값 " << *pos << "가 발견되었음";
	cout << endl;

	return 0;
}
*/

//STL 예제(map)
/*
int main(void) {
	map<string, string> myMap;
	map<string, string>::iterator it;
	string one, two, search;

	for (int i = 0; i < 6; i++) {
		cin >> one;
		cin >> two;
		myMap.insert(make_pair(one, two));
	}
	for (it = myMap.begin(); it != myMap.end(); it++) {
		cout << it->first << " :: " << it->second << endl;
	}

	cout << "사전에 해당 단어가 있는지 검색하시오. : ";
	cin >> search;
	
	auto pos = myMap.find(search);
	if (pos != myMap.end()) {
		cout << pos->first << " :: " << pos->second << " 값을 찾음" << endl;
	}
	else {
		cout << search << " 값을 찾지 못함." << endl;
	}
	
	return 0;
}
*/

//STL 예제(stack)
/*
int main(void) {
	stack<int> st;
	st.push(200);
	st.push(100);
	st.push(300);

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}

	return 0;
}
*/

//STL 예제(queue)
/*
int main(void) {
	queue<int> q;
	q.push(200);
	q.push(100);
	q.push(300);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}
*/

//예외처리
/*
int main(void) {
	int pizza, human, avg;

	cout << "피자 조각수를 입력하시오. : ";
	cin >> pizza;
	cout << "사람수를 입력하시오. : ";
	cin >> human;

	try {
		if (human <= 0)
			throw human;
		if (pizza <= 0)
			throw "a";
		avg = pizza / human;
		cout << "한 사람당 " << avg << "조각씩 먹으면 됩니다." << endl;
	}
	catch (int e) {
		cout << "사람이 " << e << "명 입니다." << endl;
	}
	catch (...) {
		cout << "피자 조각이 오류입니다." << endl;
	}
	return 0;
}
*/

//template 예제
/*
template<typename T>
class Box {
private:
	T length;
public:
	Box() : length(0) {
		cout << "기본 Box 생성자입니다." << endl;
	}

	Box(T length) {
		this->length = length;
		cout << "매개변수가 있는 Box 생성자입니다." << endl;
	}

	void Print() {
		cout << length << endl;
	}
};

int main(void) {
	Box<int> ib(100);
	Box<double> db(3.14159);

	ib.Print();
	db.Print();
	return 0;
}
*/