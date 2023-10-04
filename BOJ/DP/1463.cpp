// 1463 1로 만들기
// https://www.acmicpc.net/problem/1463
#include <iostream>

using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}

int main(void) {
	int n;

	cin >> n;
	//dp 테이블 생성
	int* dp = new int[n + 1];
	for (int i = 0; i <= n; ++i)
		dp[i] = 0;

	// dp[1] = 0
	// dp[2] = 1
	// dp[3] = 1
	// dp[4] = 2
	// 보텀업 방식으로 
	//즉 먼저 dp[i] = dp[i-1] + 1 ->  -1 
	// 5,3,2는 해당 i가 나눠 떨어지는지 체크
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1; // -1
		
		if (i % 3 == 0)
			dp[i] = Min(dp[i / 3] + 1, dp[i]);
		if (i % 2 == 0)
			dp[i] = Min(dp[i / 2] + 1, dp[i]);
	}

	cout << dp[n] << '\n';
	free(dp); //메모리 해제
	return 0;
}