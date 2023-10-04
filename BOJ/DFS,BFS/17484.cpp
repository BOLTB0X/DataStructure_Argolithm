#include <iostream>
#include <queue>

using namespace std;

int N, M, res = 98765432;
int board[6][6];
int dir[3][2] = {{1,-1}, {1, 0}, {1, 1}};

struct info {
    int x, y, preX, preY, total;
};

int mn(int a, int b) {
    return a < b ? a : b;
}

int solution(void) {
    int answer = 0;
    queue<info> que;

    for (int i = 0; i < M; ++i)
    {
        info start = {0, i, 0, 0, board[0][i]};
        que.push(start);
    }

    while (!que.empty())
    {
        info cur = que.front();
        que.pop();

        for (auto& d: dir)
        {
            int nx = cur.x + d[0];
            int ny = cur.y + d[1];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            if (d[0] == cur.preX && d[1] == cur.preY) continue;


            if (nx == N-1)
            {
                res = mn(res, cur.total+board[nx][ny]);
            } else {
                que.push({nx, ny, d[0], d[1], cur.total+board[nx][ny]});
            }
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