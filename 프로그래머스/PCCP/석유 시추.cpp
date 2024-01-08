// https://school.programmers.co.kr/learn/courses/30/lessons/250136

#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n = 500, m = 500;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

bool visited[500][500];
vector<vector<int>> board;
vector<pair<int, set<int>>> areas; // 넓이, col 좌표들

int max(int a, int b) { return a > b ? a : b; }

void BFS(int y, int x) {
    int ret = 1;
    queue<pair<int,int>> que;
    set<int> areaCol;
    
    que.push({y,x});
    areaCol.insert(x);
    visited[y][x] = true;
    
    while (!que.empty()) {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();
        
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            
            if (board[ny][nx] == 0 || visited[ny][nx]) { continue; }
            
            que.push({ny, nx});
            visited[ny][nx] = true;
            ret++;
            areaCol.insert(nx);
        }
    }

    areas.push_back({ret, areaCol});
    return;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size(), m = land[0].size();
    board = land;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (land[i][j] == 0 || visited[i][j]) {
                continue;
            }
            BFS(i, j);
        }
    }
    
    int colAmount[501] = {0};
    for (int i; i < areas.size(); ++i) {
        for (auto it: areas[i].second) {
            colAmount[it] += areas[i].first;
            answer = max(answer, colAmount[it]);
        }
    }
    
    return answer;
}