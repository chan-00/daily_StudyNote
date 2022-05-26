#include<iostream>
#include<fstream>
#include<vector>
#include<thread>

using namespace std;

// 파일 입출력 예제01
/*
int main(void) {
	ifstream is;
	ofstream os;

	int number;
	char name[30];
	int score;

	if (!is) {
		cerr << "파일 오픈 실패" << endl;
		exit(1);
	}
	is.open("score.txt");
	os.open("result.txt");

	for (int i = 0; i <= 2; i++) {
		is >> number >> name >> score;
		cout << number << " " << name << " " << score << " " << endl;
		os << number << " " << name << " " << score << " " << endl;
	}

	return 0;
}
*/

//파일 입출력 예제02
/*
int main(void) {
	ofstream os{ "output.txt", ios::app };		//ios::app -> 기존 데이터 뒤에 추가
	
	os << "추가된 작업 줄 #1" << endl;
	os << "추가된 작업 줄 #2" << endl;

	return 0;
}
*/

//파일 입출력 예제03
//output.txt 파일 안의 내용
//1 24.0
//2 32.3
//3 43.3
/*
class TempData {
public:
	int hour;
	double temp;
};

int main(void) {
	ifstream is{ "output.txt" };
	vector<TempData>temps;								//벡터 활용
	int hour;
	double temp;

	while (is >> hour >> temp) {
		temps.push_back(TempData{ hour, temp });
	}

	for (TempData t : temps) {
		cout << t.hour << " 시 온도 : " << t.temp << endl;
	}

	return 0;
}
*/

//쓰레드 사용 예제01
/*
//실행 단위를 만듦
void func1(int value) {
	for (int i = 0; i < 100; i++)
		cout << "1 ";
}

void func2(int value) {
	for (int i = 0; i < 100; i++)
		cout << "2 ";
}

int main(void) {
	thread t1(&func1, 1000);			//1000 매개변수 전달
	thread t2(&func2, 2000);			//2000 매개변수 전달

	//아래의 join과 위치를 바꿨을 때 실행 순서는?
	t1.join();						
	t2.join();

	for (int i = 0; i < 50; i++) {
		cout << "0 ";
	}

	//join을 쓰지 않으면 쓰레드 종료 전 프로그램이 끝나 런타임 오류가 발생한다.
	//프로그램이 끝날 때 까지 밑으로 내려가지 않겠다는 뜻(안전장치)
	//t1.join();						
	//t2.join();

	return 0;
}
*/

//쓰레드 사용 예제02
/*
class Counter {
public:
	void func(int id, int num) {
		for (int i = 1; i <= num; i++)
			cout << "Count [" << id << "] : " << i << endl;
	}
};

int main(void) {
	Counter c1, c2;
	//c1 객체의 func 함수에 매개변수로 1과 50을 넣어 줬다는 뜻
	thread t1(&Counter::func, &c1, 1, 50);
	thread t2(&Counter::func, &c2, 2, 50);

	t1.join();
	t2.join();

	return 0;
}
*/
