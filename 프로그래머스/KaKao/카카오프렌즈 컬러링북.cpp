// 2017 카카오코드 예선 카카오프렌즈 컬러링북
#include <vector>
#include <queue>

using namespace std;

bool visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int BFS(int m, int n, int y, int x, vector<vector<int>> picture) {
    int ret = 1;
    queue<pair<int,int>> que;
    que.push({y, x});
    visited[y][x] = true;
    
    while (que.empty() == 0) {
        int cy = que.front().first;
        int cx = que.front().second;
        que.pop();
        
        for (int d = 0; d < 4; ++d) {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            
            if (ny >= 0 && nx >= 0 && ny < m && nx < n) {
                if (visited[ny][nx]) {
                    continue;
                }
                
                if (picture[ny][nx] != picture[y][x]) {
                    continue;
                }
                
                que.push({ny,nx});
                visited[ny][nx] = true;
                ret++;
            }
        }
    }
    
    return ret;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }
    
    vector<int> answer(2);
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (picture[i][j] != 0 && !visited[i][j]) {
                int ret = BFS(m, n, i, j, picture);
                if (answer[1] < ret) {
                    answer[1] = ret;
                }
                answer[0]++;
            }
        }
    }

    return answer;
}