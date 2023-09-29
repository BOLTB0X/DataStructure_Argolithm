// 2748 피보나치 수 2
// https://www.acmicpc.net/problem/2748
#include <iostream>
#define LL long long
using namespace std;

int main(void) {
    LL n;
    LL dp[91] = {0, };

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];

    return 0;
}