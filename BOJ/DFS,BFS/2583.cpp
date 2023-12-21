// 2583 영역 구하기
// https://www.acmicpc.net/problem/2583
#include <iostream>
#include <algorithm>

using namespace std;

int M, N, K, path = 0;
int board[101][101];
int visited[101][101];
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int x, int y) {
    visited[x][y] = 1;
    path++;

    for (auto d: dir) {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

        if (visited[nx][ny] || board[nx][ny]) continue;

        DFS(nx, ny);
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[100001];
    int x1, y1, x2, y2, idx = 0;

    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = y1; x < y2; ++x) {
            for (int y = x1; y < x2; ++y) {
                board[x][y] = 1;
                visited[x][y] = 1;
            }
        }
    }
    
    // for (int x = 0; x < M; ++x) {
    //     for (int y = 0; y < N; ++y) {
    //         cout << board[x][y] << ' ';
    //     }
    //     cout << '\n';
    // }
    

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!board[i][j] && !visited[i][j]) {
                DFS(i, j);
                arr[idx++] = path;
                path = 0;
            }
        }
    }
    

    sort(arr, arr+idx);
    cout << idx << '\n';
    for (int i = 0; i < idx; ++i) cout << arr[i] << '\n';

    return 0;
}