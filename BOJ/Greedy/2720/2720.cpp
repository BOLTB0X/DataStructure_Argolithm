// 2720 세탁소 사장 동혁
// https://www.acmicpc.net/problem/2720
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    int type[4] = {25, 10, 5, 1};

    cin >> T;

    while (T--)
    {
        cin >> N;
        int answer = 0;

        for (int i = 0; i < 4; ++i)
        {
            cout << N / type[i] << ' ';
            N %= type[i];
        }
        cout << '\n';
    }
    

    return 0;
}