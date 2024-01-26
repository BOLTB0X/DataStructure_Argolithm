#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> seq;

	int number1 = 1, number2 = 2;
	for (int i = 0; i < n; ++i) {
		// 4의 배수이면
		if (i != 0  && i % 4 == 0) {
			int value = number2 * (number2 + 1) * (number2 + 2);
			seq.push_back(value);
			value = 0;
			number2++;
		}
		else {
			int value = number1 * (number1 + 1);
			seq.push_back(value);
			number1++;
		}
	}

	answer = seq[n - 1];
	return answer;
}
int main(void) {
	int n;
	cin >> n;

	int ret = solution(n);
	cout << ret;

	return 0;
}