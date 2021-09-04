#include <iostream>
#include <cmath>
using namespace std;

bool is_prime_number(int n) {
	for (int i = 2; i < ((int)sqrt(n) + 1); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}