// 15486 퇴사 2
// https://www.acmicpc.net/problem/15486
#include <iostream>
#include <vector>

using namespace std;

int mx(int a, int b) {
    return a > b ? a : b;
}

int solution(int N, vector<pair<int,int>> info) {
    int answer = 0;
    vector<int> P(N, 0), T(N, 0), dp(N+1, 0);

    for (int i = 0; i < N; ++i) {
        T[i] = info[i].first;
        P[i] = info[i].second;
        dp[i] = P[i];
    }

    for (int i = N-1; i >= 0; --i)
    {
        if (i + T[i] > N)
            dp[i] = dp[i+1];
        else
            dp[i] = mx(dp[i + T[i]]+P[i], dp[i+1]);
    }


    // for (int i = 0; i <= N; ++i)
    // {
    //     cout <<  dp[i] << ' ';
    // }
    // cout << '\n';
    answer = dp[0];

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<pair<int,int>> info;

    cin >> N;
    info = vector<pair<int,int>> (N);
    for (int i = 0; i < N; ++i)
    {
        cin >> info[i].first >> info[i].second;
    }

    cout << solution(N, info);

    return 0;
}