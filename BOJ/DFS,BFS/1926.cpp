// 1926 그림
// https://www.acmicpc.net/problem/1926
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, cnt;
int board[501][501];
int visited[501][501];
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int x, int y) {
    visited[x][y] = 1;
    cnt++;

    for (auto d : dir) {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        if (!board[nx][ny]|| visited[nx][ny]) continue;

        DFS(nx, ny);
    }

    return;
}

void solution(void) {
    vector<int> answer;
    int maxArea = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j] && board[i][j]) {
                cnt = 0;
                DFS(i, j);
                //cout << cnt << '\n';
                if (cnt >= maxArea) maxArea = cnt;
                //cout << i << ' ' << j << '\n';
                answer.push_back(cnt);
            }
        }
    }

    cout << answer.size() << '\n';
    cout << maxArea << '\n';
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    solution();
    return 0;
}