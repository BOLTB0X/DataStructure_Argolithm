// 3085 사탕 게임
// https://www.acmicpc.net/problem/3085
#include <iostream>
#include <string>

using namespace std;

int N, answer = 0;
char board[51][51];

int mx(int a, int b) {
    return a > b ? a : b;
}

void swap(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b= tmp;

    return;
}

int check(void) {
    int res = 1;

    for (int i = 0; i < N; ++i) {
        int cnt = 1;
        for (int j = 0; j < N - 1; ++j) {
            if (board[i][j] == board[i][j+1]) cnt++;
            else {
                res = mx(res, cnt);
                cnt = 1;
            }
        }
        res = mx(res, cnt);
    }

    for (int i = 0; i < N; ++i) {
        int cnt = 1;
        for (int j = 0; j < N-1; ++j) {
            if (board[j][i] == board[j+1][i]) {
                cnt++;
            } else {
                res = mx(res, cnt);
                cnt = 1;
            }
        }
        res = mx(res, cnt);
    }

    return res;
}

int solution(void) {
    int answer = 0;

     // 탐색 시작
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j) {
            if (board[i][j] != board[i][j+1]) {
                swap(&board[i][j], &board[i][j+1]);
                answer = mx(check(), answer);
                swap(&board[i][j], &board[i][j+1]);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N-1; ++j) {
            if (board[j][i] != board[j+1][i]) {
                swap(&board[j][i], &board[j+1][i]);
                answer = mx(answer, check());
                swap(&board[j][i], &board[j+1][i]);
            }
        }
    }

    return answer;
}

int main(void) {
    string tmp;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        cin >> tmp;
        for (int j = 0; j < N; ++j) {
            board[i][j] = tmp[j];
        }
    }

    cout << solution();

    return 0;
}