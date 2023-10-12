// 1912 연속합
// https://www.acmicpc.net/problem/1912
#include <iostream>
#include <vector>

using namespace std;

int mx(int a, int b) {
    return a > b ? a : b;
}

int solution(int N, vector<int> seq) {
    int answer = seq[0];
    vector<int> dp(N, 0);

    dp[0] = seq[0];
    for (int i = 1; i < N; ++i)
    {
        dp[i] = mx(dp[i-1]+seq[i], seq[i]);
        answer = mx(answer, dp[i]);
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<int> seq;

    cin >> N;
    seq = vector<int> (N);

    for (int i = 0; i < N; ++i)
        cin >> seq[i];

    cout << solution(N, seq);

    return 0;
}