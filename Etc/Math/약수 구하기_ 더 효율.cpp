#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	for (int i = 1; i*i <= n; i++) {
		if (i * i == n) {
			//�ߺ��Ǵ� ������
			cout <<  "�ߺ��Ǵ� ���� �� " << i << '\n';
		}
		else if (n % i == 0) {
			cout <<  n << "�� ���: " << i << ',' << n / i << '\n';
		}
	}
	return 0;
}