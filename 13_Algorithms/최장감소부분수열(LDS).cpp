#include <iostream>

using namespace std;

int solution(int n, int* arr) {
	int answer = 0;
	// 동적할당
	int* dp = new int[n + 1];

	// 최장 수열이므로 1로 초기화
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = 1;

		for (int j = 1; j < i; ++j) {
			//길다면
			if (arr[i] < arr[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}

		if (answer < dp[i])
			answer = dp[i];
	}

	return answer;
}

int main(void) {
	int n;

	cin >> n;
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];

	int ret = solution(n, arr);
	cout << ret;

	delete[] arr;
	return 0;
}