// 2579 계단 오르기
// https://www.acmicpc.net/problem/2579
#include <iostream>
#include <vector>
#define LL long long

using namespace std;

LL mx(LL a, LL b) {
    return a > b ? a : b;
}

LL solution(int N, vector<int> steps) {
    LL answer = 0;
    vector<LL> dp(N, 0);

    dp[0] = steps[0];
    dp[1] = steps[0] + steps[1];
    dp[2] = mx(steps[0] + steps[2], steps[1]+steps[2]);

    for (int i = 3; i < N; ++i)
    {
        // 
        dp[i] = mx(dp[i-3]+steps[i]+steps[i-1], dp[i-2] + steps[i]); 
    }

    //cout << dp[N-1] << '\n';
    answer = dp[N-1];
    return answer;
}

int main(void) {
    int N;
    vector<int> steps;

    cin >> N;
    steps = vector<int> (N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> steps[i];
    }

    cout << solution(N, steps);
    return 0;
}