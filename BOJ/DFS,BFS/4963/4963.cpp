// 4963 섬의 개수
// https://www.acmicpc.net/problem/4963
#include <iostream>
#include <vector>

using namespace std;

int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

void DFS(vector<vector<int>> board, vector<vector<int>> &visited, int x, int y) {
    visited[x][y] = 1;

    for (auto& d: dir)
    {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
            continue;
        
        if (visited[nx][ny] || !board[nx][ny]) continue;

        DFS(board, visited, nx, ny);
    }
    
    return;
}

int solution(int h, int w, vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> visited(h, vector<int> (w, 0));

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (board[i][j] && !visited[i][j])
            {
                DFS(board, visited, i, j);
                answer++;
            }
        }
    }

    return answer;
}

int main(void) {
    int T, w, h;
    vector<vector<int>> board;

    while (1)
    {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        board = vector<vector<int>> (h, vector<int>(w, 0));

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> board[i][j];
            }
        }

        cout << solution(h, w, board) << '\n';
    }
    return 0;
}