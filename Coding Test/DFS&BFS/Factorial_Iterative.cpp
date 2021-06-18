#include <iostream>
using namespace std;

int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int main(void) {
	cout << "반복적으로 구현: " << factorial(5);
}