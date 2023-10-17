// 3085 사탕 게임
// https://www.acmicpc.net/problem/3085
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<string> board;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int mx(int a, int b) {
    return a > b ? a : b;
}

int getEatingCandy(void) {
    int ret = 0;

    for (int i = 0; i < N; ++i)
    {
        int cnt = 1;
        for (int j = 0; j < N-1; ++j)
        {
            if (board[i][j] == board[i][j+1]) cnt++;
            else {
                ret = mx(ret, cnt);
                cnt = 1;
            }
        }
        ret = mx(ret, cnt);
    }

    for (int i = 0; i < N; ++i)
    {
        int cnt = 1;
        for (int j = 0; j < N-1; ++j)
        {
            if (board[j][i] == board[j+1][i]) cnt++;
            else {
                ret = mx(ret, cnt);
                cnt = 1;
            }
        }
        ret = mx(ret, cnt);
    }

    return ret;
}

int solution(void) {
    int answer = 0;

    // 가로 검사
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N-1; ++j)
        {
            if (board[i][j] != board[i][j+1])
            {
                swap(board[i][j], board[i][j+1]);
                answer = mx(answer, getEatingCandy());
                swap(board[i][j], board[i][j+1]);

            }
        }
    }

    // 세로 검사
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N-1; ++j)
        {
            if (board[j][i] != board[j+1][i])
            {
                swap(board[j][i], board[j+1][i]);
                answer = mx(answer, getEatingCandy());
                swap(board[j][i], board[j+1][i]);

            }
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
    }

    cout << solution();

    return 0;
}