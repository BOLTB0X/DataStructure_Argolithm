// 3184 양
// https://www.acmicpc.net/problem/3184
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int R, C;
vector<string> board;
vector<vector<int>> visited;

void BFS(int& oCnt, int& vCnt, int sx, int sy) {
    queue<pair<int,int>> que;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    que.push({sx, sy});

    if (board[sx][sy] == 'v') vCnt++;
    else if (board[sx][sy] == 'o') oCnt++;

    while (!que.empty())
    {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (auto d: dir) {
            int nx = cx + d[0];
            int ny = cy + d[1];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

            if (visited[nx][ny] || board[nx][ny] == '#') continue;

            if (board[nx][ny] == 'v') vCnt++;
            if (board[nx][ny] == 'o') oCnt++;

            visited[nx][ny] = 1;
            que.push({nx, ny});
        }
    }
    

    return;
}

pair<int,int> solution(void) {
    pair<int,int> answer = {0, 0};
    queue<pair<int,int>> que;
    visited = vector<vector<int>>(R, vector<int> (C, 0));

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (board[i][j] != '#' && !visited[i][j]) {
                int oCnt = 0, vCnt = 0;
                visited[i][j] = 1;

                BFS(oCnt, vCnt, i, j);
                if (vCnt >= oCnt) answer.second += vCnt;
                else answer.first += oCnt;
            }
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string tmp;

    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> tmp;
        board.push_back(tmp);
    }

    pair<int,int> ret = solution();
    cout << ret.first << ' ' << ret.second;

    return 0;
}