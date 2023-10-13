// 14467 소가 길을 건너간 이유 1
// https://www.acmicpc.net/problem/14467
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, idx, cur, answer = 0;
    cin >> N;
    vector<int> cows(11, -1);

    for (int i = 0; i < N; ++i)
    {
        cin >> idx >> cur;
        if (cows[idx] != -1 && cows[idx] != cur)
        {
            answer++;
        }
        cows[idx] = cur;
    }

    cout << answer << '\n';
    return 0;
}