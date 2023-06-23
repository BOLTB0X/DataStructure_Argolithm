#include <iostream>

using namespace std;

void check_number(int n) {
	if (n == 0) {
		cout << 0 << ' ';
		return;
	}
	while (n != 0) {
		int d = n % 10;
		cout << d << ' ';
		n /= 10;
	}
	return ;
}

int main(void) {
	int number = 124334;

	cout << number << '\n';
	check_number(number);
	cout << '\n';
	
	number = 24241;
	cout << number << '\n';
	check_number(number);
	cout << '\n';

	number = 0;
	cout << 0 << '\n';
	check_number(number);
	cout << '\n';

	
	return 0;
}