// 11047 동전 0
// https://www.acmicpc.net/problem/11047
#include <iostream>
#define LL long long

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    LL K, coins[11], answer = 0;

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }

    for (int i = N-1; i>=0; --i)
    {
        answer += (K / coins[i]);
        K %= coins[i];
    }

    cout << answer;
    return 0;
}