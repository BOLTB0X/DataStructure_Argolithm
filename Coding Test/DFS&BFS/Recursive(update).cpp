#include <iostream>
using namespace std;

void recursive_Function(int i) {
	if (i == 100) return;
	cout << i << "��° ��� �Լ��� ȣ��" << endl;
	recursive_Function(i+1);
}

int main(void) {
	recursive_Function(1);
}