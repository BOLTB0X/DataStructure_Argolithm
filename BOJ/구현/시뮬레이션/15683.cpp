// 15683 감시
// https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct camera {
    int x, y, idx;
};

int N, M, res = 98765432;
int board[9][9];
const int turnCount[5] = {4, 2, 4, 4, 1};
vector<camera> cctv;

void twoD_Copy(int (*from)[9], int (*to)[9]) {
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            to[i][j] = from[i][j];
        }
    }
    return;
}

int getScore(void) {
    int ret = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 0) ret++;
        }
    }
    return ret;
}

void boardUpdate(int dir, int cx, int cy) {
    dir = dir % 4;
    // 동북서남
    if (dir == 0) // 동
    {
        for (int i = cy; i < M; ++i)
        {
            if (board[cx][i] == 6) // 벽을 만나는 경우
            {
                break;
            }

            if (board[cx][i] == -1 || board[cx][i] != 0)
                continue;

            board[cx][i] = -1; // 벽처리
        }
    } else if (dir == 2) // 서
    {
        for (int i = cy; i >= 0; --i)
        {
            if (board[cx][i] == 6) // 벽을 만나는 경우
            {
                break;
            }

            if (board[cx][i] == -1 || board[cx][i] != 0)
                continue;

            board[cx][i] = -1; // 벽처리
        }

    } else if (dir == 1) // 북
    {
        for (int i = cx; i >= 0; --i)
        {
            if (board[i][cy] == 6) break;

            if (board[i][cy] == -1 || board[i][cy] != 0)
                continue;

            board[i][cy] = -1;
        }

    } else if (dir == 3) // 남
    {
        for (int i = cx; i < N; ++i)
        {
            if (board[i][cy] == 6) break;

            if (board[i][cy] == -1 || board[i][cy] != 0)
                continue;

            board[i][cy] = -1;
        }
    }

    return;
}

// CCTV 찾기
// 백트래킹
void backTracking(int depth) {
    if (cctv.size() == depth)
    {
        res = min(res, getScore());
        return;
    }

    int backup[9][9];
    memset(backup, 0, sizeof(backup));
    int cctvType = cctv[depth].idx;
    int cx = cctv[depth].x, cy = cctv[depth].y;

    for (int t = 0; t < turnCount[cctvType]; ++t)
    {
        twoD_Copy(board, backup);
        switch (cctvType)
        {
        case 0:
            boardUpdate(t, cx, cy);
            break;
        case 1:
            boardUpdate(t, cx, cy);
            boardUpdate(t+2, cx, cy);
            break;
        case 2:
            boardUpdate(t, cx, cy);
            boardUpdate(t+1, cx, cy);
            break;
        case 3:
            boardUpdate(t, cx, cy);
            boardUpdate(t+1, cx, cy);
            boardUpdate(t+2, cx, cy);
            break;
        case 4:
            boardUpdate(t, cx, cy);
            boardUpdate(t+1, cx, cy);
            boardUpdate(t+2, cx, cy);
            boardUpdate(t+3, cx, cy);
            break;
        }

        backTracking(depth+1);
        twoD_Copy(backup, board);
    }
    
    return;
}

void solution(void) {
    //  카메라 찾기
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] >= 1 && board[i][j] <= 5)
            {
                cctv.push_back({i, j, board[i][j]-1});
            }
        }
    }

    // 카메라를 각 하나씩 회전가능을 것을 다 해보고 최댓값을 리턴
    backTracking(0);

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    solution();
    cout << res;
    return 0;
}