// 1012 유기농 배추
// https://www.acmicpc.net/problem/1012
#include <iostream>
#include <vector>

using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(vector<vector<int>> board, vector<vector<bool>> &visited, int N, int M, int x, int y)
{
    visited[x][y] = true;

    for (auto &d: dir)
    {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

        if (visited[nx][ny] || !board[nx][ny]) continue;

        DFS(board, visited, N, M, nx, ny);
    }
    return;
}

int solution(int N, int M, vector<vector<int>> board) {
    int answer = 0;

    vector<vector<bool>> visited(N, vector<bool> (M, false));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] && !visited[i][j])
            {
                DFS(board, visited, N, M, i, j);
                answer++;
            }
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, M, N, Cnt;
    vector<vector<int>> board;

    cin >> T;
    while (T--)
    {
        cin >> M >> N >> Cnt;
        board = vector<vector<int>> (N, vector<int> (M, 0));
        int x, y;

        for (int i = 0; i < Cnt; ++i)
        {
            cin >> y >> x;
            board[x][y] = 1;
        }

        cout << solution(N, M, board) << '\n';
    }
    

    return 0;
}