#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool flag = true;
int visited[5][5];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void DFS(vector<string> place, int x, int y, int depth) {
    if (!flag) // 불통이 나왔다면
        return;
    
    if (depth == 2) {
        return;
    }
    
    for (auto &d: dir) {
        int nx = x + d[0];
        int ny = y + d[1];
        
        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        
        if (visited[nx][ny]) continue;
        
        if (place[nx][ny] == 'X') continue;
        
        if (depth < 2 && place[nx][ny] == 'P') {
            flag = false;
            return;
        }
        
        visited[nx][ny] = 1;
        DFS(place, nx, ny, depth+1);
        visited[nx][ny] = 0;
    }
    
    return;
}

bool checkPlaces(vector<string> place) {
    flag = true;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) 
        {
            if (place[i][j] == 'P') 
            {
                memset(visited, 0, sizeof(visited));
                visited[i][j] = 1;
                DFS(place, i, j, 0);
            }
        }
    }
    
    return flag;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto &place: places) {
        int check = checkPlaces(place);
        answer.push_back(check);
    }
    return answer;
}