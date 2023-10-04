// 9095 1,2,3 더하기
// https://www.acmicpc.net/problem/9095
#include <iostream>

using namespace std;

int main(void) {
    int T, N;

    // 1 : 1
    // 2 : 1+1, 2 -> 2
    // 3 : 1+1+1, 2+1, 1+2, 3 -> 4

    // 4: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1 -> 7
    // 5: 13
    // 6 24
    // 7 44
    int *dp = new int[12];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 12; ++i)
    {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }

    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        cout << dp[N] << '\n';
    }

    delete[] dp;
    return 0;
}