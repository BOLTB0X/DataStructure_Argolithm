// 1051 숫자 정사각형
// https://www.acmicpc.net/problem/1051
#include <iostream>

using namespace std;

int N, M;
int board[51][51];

int mx(int a, int b) {
    return a > b ? a : b;
}

int mn(int a, int b) {
    return a < b ? a : b;
}


int main(void) {
    int answer = -1;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            scanf("%1d", &board[i][j]);
        }
    }

    int maxLangth = mn(N, M);

    for (int l = 0; l < maxLangth; ++l)
    {
        for (int i = 0; i < N-l; ++i)
        {
            for (int j = 0; j < M-l; ++j)
            {
                if (board[i][j] == board[i+l][j] && board[i][j] == board[i][j+l] &&
                    board[i][j] == board[i+l][j+l])
                    {
                        answer = mx(answer, (l+1)*(l+1));
                    }
            }
        }
    }

    cout << answer;
    return 0;
}