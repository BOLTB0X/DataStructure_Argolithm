// 2563 색종이
// https://www.acmicpc.net/problem/2563
#include <iostream>

using namespace std;

int board[101][101];

int main(void) {
    int N;
    int x, y, answer = 0;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;

        for (int j = y; j < y+10; ++j)
        {
            for (int k = x; k < x+10; ++k)
            {
                board[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (board[i][j]) answer++;
        }
    }

    cout << answer << '\n';
    return 0;
}