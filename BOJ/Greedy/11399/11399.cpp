// 11399 ATM
// https://www.acmicpc.net/problem/11399
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    // 3 1 4 3 2
    // 1 2 3 3 4

    int N, answer = 0;
    int time[1001];
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> time[i];
    }

    sort(time, time+N);
    int prefixSum = 0;
    for (int i = 0; i < N; ++i)
    {
        prefixSum += time[i];
        answer += prefixSum;
    }

    cout << answer << '\n';
    return 0;
}