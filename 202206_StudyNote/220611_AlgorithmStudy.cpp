#include<iostream>
#include<cstring>
using namespace std;

//스택 이용하여 중위 -> 후위식 변경 예제
/*
class Stack {
private:
	char str[50];
	int strLeng;
	int top;
public:
	Stack(int leng) : strLeng(leng + 1) ,top(-1) {
		cout << "50 길이의 스택 생성 완료!" << endl;
	}

	bool isFull() {
		if (top >= strLeng - 1)
			return true;
		else
			return false;
	}

	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}

	void Push(char c) {
		if (!isFull())
			str[++top] = c;
		else
			cout << "스택이 가득 찼습니다!" << endl;
	}

	char Pop() {
		if (!isEmpty())
			return str[top--];
		else
			cout << "스택이 비어 있으므로 pop을 할 수 없습니다!" << endl;
	}

	int getTop() {
		return top;
	}
};

int main(void) {
	char str[50];
	int leng;

	cout << "중위식을 입력하세요 : ";
	cin >> str;
	leng = strlen(str);

	//스택 객체 생성
	Stack stack(leng);

	for (int i = 0; i < leng; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
		else if (str[i] == ')')
			cout << stack.Pop();
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			stack.Push(str[i]);
	}

	while (stack.getTop() != -1)
		cout << stack.Pop();
	cout << endl;

	return 0;
}
*/

//이진 트리 전위/중위/후위 순회 예제
/*
//전위 순회
void preOrder(const char* tree, int loc) {
	if (loc >= strlen(tree))
		return;
	if (tree[loc] != '0') {
		cout << tree[loc];
		preOrder(tree, loc * 2);
		preOrder(tree, (loc * 2) + 1);
	}
}

//중위 순회
void inOrder(const char* tree, int loc) {
	if (loc >= strlen(tree))
		return;
	if (tree[loc] != '0') {
		inOrder(tree, loc * 2);
		cout << tree[loc];
		inOrder(tree, (loc * 2) + 1);
	}
}

//후위 순회
void postOrder(const char* tree, int loc) {
	if (loc >= strlen(tree))
		return;
	if (tree[loc] != '0') {
		postOrder(tree, loc * 2);
		postOrder(tree, (loc * 2) + 1);
		cout << tree[loc];
	}
}

int main(void) {
	char tree[50] = { 7, 'A', 'B', 'C', 'D', '0', 'E', 'F', '0', '0', '0', '0', '0', '0', '0', 'G', '0' };
	cout << "<전위 순회>" << endl;
	preOrder(tree, 1);
	cout << endl;
	cout << "<중위 순회>" << endl;
	inOrder(tree, 1);
	cout << endl;
	cout << "<후위 순회>" << endl;
	postOrder(tree, 1);
	cout << endl;

	return 0;
}
*/
