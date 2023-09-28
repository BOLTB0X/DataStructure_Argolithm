// 14940 쉬운 최단거리
// https://www.acmicpc.net/problem/14940
#include <iostream>
#include <queue>

using namespace std;

int answer[1002][1002];
int board[1002][1002];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void BFS(int n, int m, int x, int y)
{
    queue<pair<int,int>> que;
    que.push({x, y});

    while (!que.empty())
    {
        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        for (auto& d: dir)
        {
            int nx = cx + d[0];
            int ny = cy + d[1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                continue;
            }

            if (answer[nx][ny] != -1 || board[nx][ny] == 0)
            {
                continue;
            }

            answer[nx][ny] = answer[cx][cy] + 1;
            que.push({nx, ny});
        }
    }
    
    return;
}

void solution(int n, int m) {
    int x, y;

    // 초기화
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            answer[i][j] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 2) {
                x = i, y = j;
                answer[i][j] = 0;
            }

            if (board[i][j] == 0)
            {
                answer[i][j] = 0;
            }
        }
    }

    BFS(n, m, x, y);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {   
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    solution(n, m);
    return 0;
}