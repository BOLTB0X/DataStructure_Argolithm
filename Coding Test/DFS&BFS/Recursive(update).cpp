#include <iostream>
using namespace std;

void recursive_Function(int i) {
	if (i == 100) return;
	cout << i << "번째 재귀 함수를 호출" << endl;
	recursive_Function(i+1);
}

int main(void) {
	recursive_Function(1);
}