// 17144 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, T;
int board[50][50];
int backup[50][50];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<int,int> robotTop;
pair<int,int> robotBottom;

void boardCopy(int (*from)[50], int (*to)[50]) {
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            to[i][j] = from[i][j];
        }
    }
    return;
}

void boardPrint(void) {
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';
}

void diffuse(int x, int y) {
    int dust = board[x][y];
    int cnt = 0;

    if (x + 1 < R && board[x+1][y] != -1) 
    {
        backup[x+1][y] += (dust/5);
        cnt++;
    }

    if (x - 1 >= 0 && board[x-1][y] != -1)
    { 
        backup[x-1][y] += (dust/5);
        cnt++;
    }

    if (y + 1 < C && board[x][y+1] != -1)
    { 
        backup[x][y+1] += (dust/5);
        cnt++;
    }

    if (y - 1 >= 0 && board[x][y-1] != -1) 
    {
        backup[x][y-1] += (dust/5);
        cnt++;
    }

    backup[x][y] -= (dust/5)*cnt;

    return;
}

void airDiffuse(void) {
    boardCopy(board, backup);
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] > 0)
            {
                diffuse(i, j);
            }
        }
    }
    boardCopy(backup, board);

    return;
}

void reverseRotate(void) {
    // 왼쪽 가로
    for (int i = robotTop.first-1; i > 0; --i)
    {
        board[i][0] = board[i-1][0];
    }

    // 왼쪽 세로
    for (int i = 0 ; i < C-1; ++i)
    {
        board[0][i] = board[0][i+1];   
    }

    // 우측 세로
    for (int i = 1; i <= robotTop.first; ++i)
    {
        board[i-1][C-1] = board[i][C-1];
    }

        // 우측 가로
    for (int i = C-1; i > 1; --i)
    {
        board[robotTop.first][i] = board[robotTop.first][i-1];
    }
    board[robotTop.first][1] = 0;

    return;
}

void commonRotate(void) {
    // 왼쪽 세로
    for (int i = robotBottom.first+1; i < R - 1; ++i)
    {
        board[i][0] = board[i+1][0];
    }

    // 아래 가로 회전 <-
    for (int i = 0; i < C - 1; ++i)
    {
        board[R-1][i] = board[R-1][i+1];
    }

    // 오른쪽 세로 회전
    for (int i = R - 1; i>= robotBottom.first; --i)
    {
        board[i][C-1] = board[i-1][C-1];
    }

    // 위쪽 가로 ->
    for (int i = C-1; i > 1; --i)
    {
        board[robotBottom.first][i] = board[robotBottom.first][i-1];
    }

    board[robotBottom.first][1] = 0;

    return;
}

void airClean(void) {
    reverseRotate();
    commonRotate();
    return;
}

int solution(void) {
    int answer = 0, flag = 0;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] == -1) 
            {
                if (!flag) 
                {
                    robotTop = {i, j};
                    flag = 1;
                } else 
                {
                    robotBottom = {i ,j};
                }
            }
        }
    }


    while (T--)
    {
        airDiffuse();
        //boardPrint();
        airClean();
        //boardPrint();
    }


    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] > 0) answer += board[i][j];
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << solution() << '\n';
    return 0;
}