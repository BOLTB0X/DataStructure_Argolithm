#include <iostream>
using namespace std;

void recursive_Function() {
	cout << "��� �Լ��� ȣ��" << endl;
	recursive_Function();
}

int main(void) {
	recursive_Function();
}