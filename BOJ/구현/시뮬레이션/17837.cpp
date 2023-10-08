// 17837 새로운 게임 2
// https://www.acmicpc.net/problem/17837
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct horse {
    int x, y, d;
};

int N, K;
vector<vector<int>> board;
vector<pair<pair<int, int>, int>> cmd;
vector<int> gameMap[13][13];
horse horses[11];
int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// 디버깅 용
void printGameMap(void) {
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (gameMap[i][j].size() > 0)
                cout << gameMap[i][j][0] << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }
}

int reverseDir(int d) {
    if (d == 1) return 2;
    else if (d == 2) return 1;
    else if (d == 3) return 4;
    return 3;
}

int check(void) {
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (gameMap[i][j].size() > 3)
                return 0;
        }
    }
    return 1;
}

void move(int hIdx) {
    // 이동해야할 말의 위치
    int hx = horses[hIdx].x;
    int hy = horses[hIdx].y;
    int hd = horses[hIdx].d;

    // 말이 이동해야할 칸
    int nx = hx + dir[hd][0];
    int ny = hy + dir[hd][1];

    // 범위 초과 및 파란 칸
    if (nx < 1 || ny < 1 || nx > N || ny > N || board[nx][ny] == 2)
    {
        horses[hIdx].d = reverseDir(hd);
        hd =  horses[hIdx].d;
        nx = hx + dir[hd][0];
        ny = hy + dir[hd][1];

        if (nx < 1 || ny < 1 || nx > N || ny > N || board[nx][ny] == 2) return;
    }

    vector<int>& cur = gameMap[hx][hy];
    vector<int>& next = gameMap[nx][ny];
    auto i = find(cur.begin(), cur.end(), hIdx);

    if (board[nx][ny] == 1) // 빨간 칸
    {
        reverse(i, cur.end());
    }

    // 이동
    for (auto j = i; j != cur.end(); ++j)
    {
        horses[*j].x = nx;
        horses[*j].y = ny;
        //horses[*j].d = hd;

        next.push_back(*j);
    }

    cur.erase(i, cur.end());
    return;
}

int solution(void) {
    int answer = 0, flag = 1;

    // 셋팅
    for (int i = 0; i < cmd.size(); ++i)
    {
        horses[i+1] = {cmd[i].first.first, cmd[i].first.second, cmd[i].second};
        gameMap[cmd[i].first.first][cmd[i].first.second].push_back(i+1);
    }

    // 시뮬레이션 시작
    // 말 이동
    // - 무슨 칸인지 확인
    // - 업데이트
    // 칸 갯수 확인
    while (++answer <= 1000)
    {
        for (int k = 1; k <= K; ++k)
        {
            move(k);
            flag = check();
            if (!flag) break;
        }
        if (!flag) break;
    }
    
    if (answer == 1001) answer = -1;
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> N >> K;
    board = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        cmd.push_back({{x, y}, d});
    }

    cout << solution();

    return 0;
}
