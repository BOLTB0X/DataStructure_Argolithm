#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

int main(void) {
	cout << "재귀적으로 반복: " << factorial(5);
}