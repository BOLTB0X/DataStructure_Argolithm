#include <iostream>

using namespace std;

int get_number_len(int n) {
	if (n == 0)
		return 1;

	int len = 0;
	while (n != 0) {
		n /= 10;
		len++;
	}
	return len;
}

int main(void) {
	int number = 214235432;

	cout << "214235432의 길이: " << get_number_len(number) << '\n';

	number = 1000;
	cout << "1000의 길이: " << get_number_len(number) << '\n';
	
	number = 0;
	cout << "0의 길이: " << get_number_len(number);
	return 0;
}