// 2210 숫자판 점프
// https://www.acmicpc.net/problem/2210
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> per;
char board[5][5];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(int x, int y, string cur, int depth)
{
    if (depth == 6)
    {
        per.insert(cur);
        return;
    }

    for (auto d: dir)
    {
        int nx = x + d[0];
        int ny = y + d[1];

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

        DFS(nx, ny, cur + board[nx][ny], depth + 1);
    }

    return;
}

int solution(void) {
    int answer = 0;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            DFS(i, j, to_string(board[i][j]), 1);
        }
    }

    answer = per.size();

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << solution();

    return 0;
}