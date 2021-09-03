#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i*i <= n; i++) {
		if (i * i == n) {
			//중복되는 제곱수
			cout <<  "중복되는 제곱 수 " << i << '\n';
		}
		else if (n % i == 0) {
			cout <<  n << "의 약수: " << i << ',' << n / i << '\n';
		}
	}
	return 0;
}