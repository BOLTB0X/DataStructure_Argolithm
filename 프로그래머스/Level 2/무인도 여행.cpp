// https://school.programmers.co.kr/learn/courses/30/lessons/154540
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> visited;
int tot = 0;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(vector<string> maps, int x, int y) {
    visited[x][y] = 1;
    tot += (maps[x][y] - '0');
    
    for (auto d: dir) {
        int nx = x + d[0];
        int ny = y + d[1];
        
        if (nx < 0 || ny <0 || nx >= maps.size() || ny >= maps[0].size())
            continue;
        if (maps[nx][ny] == 'X' || visited[nx][ny]) continue;
        
        DFS(maps, nx, ny);
    }
    
    return;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    visited = vector<vector<int>> (maps.size(), vector<int>(maps[0].size(), 0));
    
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[i].size(); ++j) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                tot = 0;
                DFS(maps, i, j);
                
                answer.push_back(tot);
            }
        }
    }
    
    if (answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}