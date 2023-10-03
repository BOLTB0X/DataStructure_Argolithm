// 1063 킹
// https://www.acmicpc.net/problem/1063
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int board[9][9];
map<string,pair<int,int>> dir = {
    {"R", {0, 1}}, 
    {"L", {0, -1}},
    {"B", {-1, 0}},
    {"T", {1, 0}},
    {"RT", {1, 1}},
    {"LT", {1,-1}},
    {"RB", {-1,1}},
    {"LB", {-1,-1}}
    };

void solution(string kingPos, string stonePos, int N, vector<string> cmd) {
    int ky = kingPos.front() - 'A' + 1;
    int kx = kingPos.back() - '0';
    int sy = stonePos.front() - 'A' + 1;
    int sx = stonePos.back() - '0';

    board[kx][ky] = 1;
    board[sx][sy] = -1;

    for (string& c: cmd)
    {
        int nkx = kx + dir[c].first;
        int nky = ky + dir[c].second;

        if (nkx < 1 || nky < 1 || nkx > 8 || nky > 8) continue;

        if (board[nkx][nky] == -1)
        {
            int nsx = sx + dir[c].first;
            int nsy = sy + dir[c].second;

            if (nsx < 1 || nsy < 1 || nsx > 8 || nsy > 8) continue;

            board[nsx][nsy] = -1;
            sx = nsx, sy = nsy;
        }

        board[nkx][nky] = 1;
        board[kx][ky] = 0;
        kx = nkx, ky = nky;
    }

    //cout << kx << ' ' << ky << '\n';
    kingPos = char(ky + 65 - 1) + to_string(kx);
    stonePos = char(sy + 65-1) + to_string(sx);
    cout << kingPos << '\n';
    cout << stonePos << '\n';
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string k1, k2;
    int N;
    vector<string> cmd;

    cin >> k1 >> k2 >> N;
    cmd = vector<string> (N);

    for (int i = 0; i < N; ++i)
    {
        cin >> cmd[i];
    }

    solution(k1, k2, N, cmd);

    return 0;
}