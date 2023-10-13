// 17484 진우의 달 여행 (Small)
// https://www.acmicpc.net/problem/17484
#include <iostream>
#include <vector>

using namespace std;

int N, M, res = 100 * 1000 + 1;
int dir[3][2] = {{1, -1}, {1, 0}, {1, 1}};
vector<vector<int>> board;

int mn(int a, int b) {
    return a < b ? a : b;
}

void DFS(int x, int y, int cur, int preDir, int depth) {
    if (depth == N) 
    {
        res = mn(res, cur);
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        if (preDir == i) continue;

        DFS(nx, ny, cur + board[nx][ny], i, depth + 1);
    }

    return;
}


void brueFocre(void) {
    // 스타트 지점을 다르게 해서 완전탐색 진행
    for (int i = 0; i < M; ++i)
    {
        DFS(0, i, board[0][i], -1, 1);
    }

    return;
}

void dynamicPrograming(void) {
    // 가장 아래서부터 진행
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int> (3, res)));
    // dp[i][j][0] : dp[i-1][j+1]의 최솟값 + board[i][j]
    // dp[i][j][1] : dp[i-1][j]의 최솟값 + board[i][j]
    // dp[i][j][2] : dp[i-1][j-1]의 최솟값 + board[i][j]

    for (int i = 0; i < N; ++i)
    {
        if (i == 0) 
        {
            for (int j = 0; j < M; ++j)
            {
                for (int k = 0; k < 3; ++k)
                {
                    dp[i][j][k] = board[i][j];
                }
            }
        } else  // 본격적인 DP?
        {
            for (int j = 0; j < M; ++j)
            {
                if (j == 0) //  (i+1, j+1) 오는 경우 X -> dp[i-1][j-1] 제외
                {
                    dp[i][j][0] = mn(dp[i-1][j+1][1], dp[i-1][j+1][2])+board[i][j];
                    dp[i][j][1] = dp[i-1][j][0] + board[i][j];
                } else if (j == M-1) // 아래, 왼쪽 대각선 (오른쪽 대각선 X)
                {
                    dp[i][j][1] = dp[i-1][j][2] + board[i][j];
                    dp[i][j][2] = mn(dp[i-1][j-1][0], dp[i-1][j-1][1])+board[i][j];
                } else 
                {
                    dp[i][j][0] = mn(dp[i-1][j+1][1], dp[i-1][j+1][2])+board[i][j];
                    dp[i][j][1] = mn(dp[i-1][j][0], dp[i-1][j][2])+board[i][j];
                    dp[i][j][2] = mn(dp[i-1][j-1][0], dp[i-1][j-1][1])+board[i][j];
                }
            }   
        }
    }

    // for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < M; ++j)
    //     {
    //         cout << dp[i][j].first << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < 3; ++j)
            res = mn(dp[N-1][i][j], res);
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board = vector<vector<int>> (N, vector<int> (M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    //brueFocre();
    dynamicPrograming();

    cout << res;
    return 0;
}