#include <iostream>

using namespace std;

long long solution(long long N) {
	long long answer = 1;
	long long plusNumber = 1;

	// 6의 배수로 커짐
	// 6, 12, 18... 조심
	while (N > plusNumber) {
		plusNumber += (6 * answer);
		answer++;
	}

	return answer;
}

int main(void) {
	long long N;

	cin >> N;

	cout << solution(N);;
	return 0;
}