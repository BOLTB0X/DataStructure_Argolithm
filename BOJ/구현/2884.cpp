// 2884 알람 시계
// https://www.acmicpc.net/problem/2884
#include <iostream>

using namespace std;

int main(void) {
    int H, M;
    cin >> H >> M;

    if (M - 45 < 0)
    {
        M = 60 + M - 45;
        H -= 1;

        if (H < 0) H = 23;

    } else {
        M -= 45;
    }

    cout << H << ' ' << M;
    return 0;
}