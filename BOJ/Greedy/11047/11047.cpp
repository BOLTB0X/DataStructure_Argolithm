// 11047 동전 0
// https://www.acmicpc.net/problem/11047
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int k, vector<int>& coins) {
	int answer = 0;

	for (int i = n - 1; i >= 0; --i) {
		if (coins[i] > k)
			continue;
		answer += (k / coins[i]);
		k %= coins[i];
	}

	return answer;
}

int main(void) {
	int n, k;
	
	cin >> n >> k;
	vector<int> coins(n, 0);
	for (int i = 0; i < n; ++i) 
		cin >> coins[i];
	
	int ret = solution(n, k, coins);
	cout << ret;

	return 0;
}