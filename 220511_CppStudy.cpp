#include<iostream>
#include<time.h>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

//리스트 사용01
/*
int main(void) {
	list<int> values;						//int형 리스트 생성

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		values.push_back(rand() % 100);		//리스트에 랜덤값 추가(뒤에다가 추가됨.)
	}
	values.sort();							//리스트 오름차순 정렬

	for (auto& e : values) {
		cout << e << " ";					//리스트 요소들 출력
	}
	cout << endl;

	return 0;
}
*/

//벡터 사용01
/*
int main(void) {
	vector<int> values;
	//vector<int>::iterator it;

	values.push_back(10);
	values.push_back(5);
	values.push_back(8);
	values.push_back(20);

//	for (vector<int>::iterator it = values.begin(); it != values.end(); it++)
//		cout << *it << " ";

	for (auto i = values.begin(); i != values.end(); ++i)
		cout << *i << " ";
	cout << endl;
	for (auto i = values.begin(); i != values.begin() + 2; ++i)
		cout << *i << " ";

//	for (auto& i : values)
//		cout << i << " ";


	return 0;
}
*/

//벡터 사용02
/*
int main(void) {
	vector<string> values;
	vector<string>::iterator it;

	values.push_back("ABCD");
	values.push_back("MILK");
	values.push_back("APPLE");

	//인덱스(i)를 사용하여 벡터값 출력(아래 for문들의 출력값은 모두 동일, 방법의 차이)
	for (int i = 0; i < values.size(); i++)
		cout << values[i] << " ";

	//반복자(it)를 사용하여 벡터값 출력
	//반복자(it)는 일반적인 값이 아닌 포인터형이기 때문에 출력 시 참조(*) 연산자 사용
//	for (it = values.begin(); it != values.end(); it++)
//		cout << *it << " ";

	//auto를 사용하여 벡터값 출력
//	for (auto i = values.begin(); i != values.end(); ++i)
//		cout << *i << " ";

	values.insert(values.begin(), "AAAA");					//벡터의 첫 위치에 AAAA 추가
	cout << endl;

	for (auto i = values.begin(); i != values.end(); ++i)
		cout << *i << " ";

	int n = values.size();
	cout << endl << "벡터의 길이 : " << n << endl;

	return 0;
}
*/

//데큐(deque) 사용
//deque는 앞과 뒤 모두 push와 pop 동작이 가능하다.(vector는 불가능)
/*
int main(void) {
	deque<int> values = { 1, 2, 3, 4, 5 };

	//deque 뒤에 10, 3 추가, 앞에 20 추가
	values.push_back(10);
	values.push_front(20);
	values.push_back(3);

	for (auto i = values.begin(); i != values.end(); i++)
		cout << *i << " ";
	cout << endl;

	//앞에서 1개, 뒤에서 1개 요소 pop 후 출력
	values.pop_front();
	values.pop_back();

	for (int i = 0; i < values.size(); i++)
		cout << values[i] << " ";

	return 0;
}
*/

//리스트 사용02
/*
int main(void) {
	list<int> values = { 1, 2, 3, 4, 5 };

	auto it = values.begin();
	it++;
	it++;
	values.insert(it, 100);
	values.push_back(10);
	values.push_front(20);
	values.push_back(3);

	values.insert(values.begin(), 3);

	for (auto& it : values)
		cout << it << " ";

	return 0;
}
*/

//집합(set) 사용
//값이 자동 오름차순 정렬되고, 중복을 허용하지 않는 것을 볼 수 있다.
/*
int main(void) {
	set<int> values = { 10, 3, 4, 5 };

	auto it = values.begin();
	it++;
	it++;
	
	//집합은 내부에서 정렬되어 나오기 때문에 values.end와 같이 위치 지정하여 값을 넣는 것이 의미가 없다.
	values.insert(it, 100);
	values.insert(values.end(), 3);
	values.insert(values.end(), 8);
	values.insert(50);

	for (auto& it : values)
		cout << it << " ";
	cout << endl;

	//find라는 함수로 특정 값을 찾을 수 있다.
	//if 조건문 비교 시 순차 검색하므로 pos가 values.end()가 아니면 값을 찾은 것으로 간주.
	auto pos = values.find(5);
	if (pos != values.end())
		cout << *pos << " 값이 있습니다." << endl;
	else
		cout << "값이 없습니다." << endl;

	return 0;
}
*/

//딕셔너리(Map) 사용
/*
int main(void) {
	map<string, string> mymap;

	//딕셔너리에 make_pair 함수를 사용하여 키값, 데이터값을 넣는다.
	mymap.insert(make_pair("김철수", "010-2345-1234"));
	mymap.insert(make_pair("이인영", "010-3333-3232"));
	//위의 방식이 아닌 이렇게 넣어도 삽입 가능.
	mymap["성안중"] = "010-2321-1234";

	//first로 키값, second로 데이터값 출력
	for (auto& it : mymap)
		cout << it.first << " : " << it.second << endl;
	cout << endl;

	if (mymap.find("이인영") != mymap.end())
		cout << "발견" << endl;
	else
		cout << "미발견" << endl;

	return 0;
}
*/

//스택 사용
//스택은 front 불가, top 함수를 사용하여 스택의 맨 위의 값만 검색 가능.
/*
int main(void) {
	stack<int> st;

	st.push(3);
	st.push(2);
	st.push(5);
	st.push(7);
	st.push(8);
	st.pop();

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
	return 0;
}
*/

//큐 사용
//큐는 front 가능, end는 사용 불가(맨 앞에 것으로만 검색 가능
/*
int main(void) {
	queue<int> qu;
	qu.push(100);
	qu.push(200);
	qu.push(300);

	//큐는 먼저 들어온 값이 먼저 나가기 때문에 이렇게 출력 시 100부터 200, 300이 출력됨.
	while (!qu.empty()) {
		cout << qu.front() << endl;
		qu.pop();
	}

	return 0;
}
*/

//람다식 사용
//람다식은 기본적으로 return 방식 함수이다.
int main(void) {
	auto sum = [](int x, int y) {return x + y; };
	auto print = []() {return "람다입니다."; };
	auto print1 = []() {cout << "람다입니다." << endl; };

	cout << sum(10, 20) << endl;
	cout << print() << endl;
	print1();

	return 0;
}