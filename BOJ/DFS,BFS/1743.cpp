// 1743 음식물 피하기
// https://www.acmicpc.net/problem/1743
#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
int board[101][101];
int visited[101][101];
int cnt;

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int x, int y) {
    visited[x][y] = 1;
    cnt++;

    for (auto d: dir)
    {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 1 || ny < 1 || nx > N || ny > M) continue;

        if (visited[nx][ny]) continue;

        if (!board[nx][ny]) continue;

        DFS(nx, ny);
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;

    cin >> N >> M >> K;
    memset(board, 0, sizeof(board));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;

        board[a][b] = 1;
    }

    // for (int i = 1; i <= N; ++i) {
    //     for (int j = 1; j <= M; ++j) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (!visited[i][j] && board[i][j]) {
                cnt = 0;
                DFS(i, j);
                //cout << cnt << '\n';
                answer = answer > cnt ? answer : cnt;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}