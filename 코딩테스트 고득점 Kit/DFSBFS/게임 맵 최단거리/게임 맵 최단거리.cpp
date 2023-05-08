#include<vector>
#include <queue>

using namespace std;

typedef struct {
    int y,x;
} Me;

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

vector<vector<int>> dist;

int BFS(vector<vector<int>>& maps, int r, int c) {
    queue<Me> que;
    dist = vector<vector<int>> (r, vector<int> (c, 0));
    
    que.push({0,0});
    dist[0][0] = 1;
    
    while(!que.empty()) {
        Me cur = que.front();
        que.pop();
        
        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            
            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            
            if (dist[ny][nx] != 0 || maps[ny][nx] == 0)
                continue;
            
            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            que.push({ny, nx});
        }
    }
    
    return dist[r - 1][c - 1] != 0 ? dist[r - 1][c - 1] : -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int row = maps.size(), col = maps[0].size();
    
    answer = BFS(maps, row, col);
    return answer;
}