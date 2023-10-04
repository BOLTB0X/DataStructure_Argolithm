// 13565 침투
// https://www.acmicpc.net/problem/13565
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> visited;

string solution(int N, int M, vector<vector<int>> board) {
    string answer = "NO";
    visited = vector<vector<bool>> (N, vector<bool> (M, false));
    queue<pair<int,int>> que;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int i = 0; i < M; ++i)
    {
        if (!board[0][i])
        {
            que.push({0, i});
            visited[0][i] = true;
        }
    }

    while (!que.empty())
    {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (auto& d: dir)
        {
            int nx = cx + d[0];
            int ny = cy + d[1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (visited[nx][ny] || board[nx][ny]) continue;

            visited[nx][ny] = true;
            que.push({nx, ny});
        }
    }
    
    for (int i = 0; i < M; ++i)
    {
        if (visited[N-1][i])
        {
            answer = "YES";
            break;
        }
    }

    return answer;
}

int main(void) {
    int N, M;
    vector<vector<int>> board;

    cin >> N >> M;
    board = vector<vector<int>> (N, vector<int> (M, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            scanf("%1d",&board[i][j]);
        }
    }

    cout << solution(N, M, board);

    return 0;
}