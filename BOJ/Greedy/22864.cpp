// 22864 피로도
// https://www.acmicpc.net/problem/22864
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 하루에 한 시간 일하면 피로도는 A
    // 하루에 한 시간 일하면 일 B
    // 한 시간을 쉰다면 피로도는 C 만큼 감소
    // 피로도를 최대한 M을 넘지 않게
    // 하루는 24

    // 5 3 2 10

    int answer = 0, day = 24, p = 0, A, B, C, M;
    cin >> A >> B >> C >> M;

    // if (A > M)
    // {
    //     cout << 0 << '\n';
    //     exit(0);
    // }

    while (day > 0)
    {
        if (p + A <= M)
        {
            p += A;
            answer += B;
        } else {
            if (p - C < 0)
            {
                p = 0;
            } else
            {
                p -= C;
            }
        }
        day--;
    }
    cout << answer << '\n';

    return 0;
}