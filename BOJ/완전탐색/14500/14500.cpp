// 14500 테트로미노
// https://www.acmicpc.net/problem/14500
#include <iostream>

using namespace std;

int N, M, res = -1;
int board[501][501];
int visited[501][501];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int mx(int a, int b) {
    return a > b ? a : b;
}

void isSpecialShape(int x, int y) {
    // ㅜ
    if (x+1 < N && y + 2 < M)
    {
        res = mx(res, board[x][y]+board[x][y+1]+board[x+1][y+1]+board[x][y+2]);
    }

    // ㅏ
    if (x+2 < N && y+1 < M)
    {
        res = mx(res, board[x][y]+board[x+1][y]+board[x+1][y+1]+board[x+2][y]);
    }

    // ㅓ
    if (x+2 < N && y - 1 >= 0)
    {
        res = mx(res, board[x][y]+board[x+1][y]+board[x+1][y-1]+board[x+2][y]);
    }

    // ㅗ
    if (x-1 >= 0 && y +2 < M)
    {
        res = mx(res, board[x][y]+board[x][y+1]+board[x-1][y+1]+board[x][y+2]);
    }
    return;
}

void DFS(int x, int y, int cellTotal, int depth) {
    if (depth == 4)
    {
        res = mx(cellTotal, res);
        return;
    }

    for (auto& d: dir)
    {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        if (visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        DFS(nx, ny, cellTotal+board[nx][ny], depth+1);
        visited[nx][ny] = 0;
    }
    return;
}

int solution(void) {
    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            visited[i][j] = 1;
            isSpecialShape(i,j);
            DFS(i,j,board[i][j], 1);
            visited[i][j] = 0;
        }
    }

    answer = res;
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << solution();
    return 0;
}