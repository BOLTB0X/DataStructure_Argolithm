// 3085 사탕 게임
// https://www.acmicpc.net/problem/3085
#include <iostream>

using namespace std;

int N, res = 0;
string board[51];

int mx(int a, int b) {
    return a > b ? a : b;
}

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void check(void) {
    // 가로 검사
    for (int i = 0; i < N; ++i)
    {
        int cnt = 1;
        for (int j = 0; j< N-1; ++j)
        {
            if (board[i][j] == board[i][j+1])
            {
                cnt++;
            } else
            {
                res = mx(cnt, res);
                cnt = 1;
            }
        }
        res = mx(cnt, res);
    }

    // 세로 검사
    for (int i = 0; i < N; ++i)
    {
        int cnt = 1;
        for (int j = 0; j< N-1; ++j)
        {
            if (board[j][i] == board[j+1][i])
            {
                cnt++;
            } else {
                res = mx(cnt, res);
                cnt = 1;
            }
        }
        res = mx(cnt, res);
    }
    return;
}

int solution(void) {
    int answer = 0;
    
    check();

    // 가로
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N-1; ++j)
        {
            if (board[i][j] != board[i][j+1])
            {
                swap(&board[i][j], &board[i][j+1]);
                check();
                swap(&board[i][j], &board[i][j+1]);

            }
        }
    }

    // 세로
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N-1; ++j)
        {
            if (board[j][i] != board[j+1][i])
            {
                swap(&board[j][i], &board[j+1][i]);
                check();
                swap(&board[j][i], &board[j+1][i]);
            }
        }
    }

    answer = res;

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) cin >> board[i];

    cout << solution();
    return 0;
}