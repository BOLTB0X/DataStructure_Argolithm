// 1932 정수 삼각형
// https://www.acmicpc.net/problem/1932
#include <iostream>
#include <vector>

using namespace std;

int mx(int a, int b) {
    return a > b ? a : b;
}

int solution(int N, vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> dp(N, vector<int> (N, 0));

    dp[0][0] = board[0][0];

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            dp[i][j] = board[i][j]+mx(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    for (int i = 0; i < N; ++i)
    {
        answer = mx(dp[N-1][i], answer);
    }

    return answer;
}

int main(void) {
    int N;
    vector<vector<int>> board;

    cin >> N;
    board = vector<vector<int>> (N, vector<int> (N, -1));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << solution(N, board);

    return 0;
}