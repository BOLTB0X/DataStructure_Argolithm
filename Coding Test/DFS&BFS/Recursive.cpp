#include <iostream>
using namespace std;

void recursive_Function() {
	cout << "재귀 함수를 호출" << endl;
	recursive_Function();
}

int main(void) {
	recursive_Function();
}