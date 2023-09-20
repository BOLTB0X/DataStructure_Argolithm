//
//  main.cpp
//  2573 빙산
//  https://www.acmicpc.net/problem/2573
//  Created by KyungHeon Lee on 2023/09/19.
//

#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int pan[300][300];
int tmp[300][300];
bool visited[300][300];

void DFS(int x, int y) {
    for (auto& d: dir) {
        int nx = x + d[0];
        int ny = y + d[1];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            continue;
        }
        
        if (visited[nx][ny] || pan[nx][ny] == 0) {
            continue;
        }
        
        visited[nx][ny] = true;
        DFS(nx, ny);
    }
    return;
}

void melting() {
    memset(tmp, 0, sizeof(tmp));
    
    for (int i = 0; i < N; ++i) {
        for (int j =0; j < M; ++j) {
            if (pan[i][j] == 0) continue;
            
            int cnt = 0;
            for (auto& d: dir) {
                int nx = i + d[0];
                int ny = j + d[1];
                
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                    continue;
                }
                
                if (!pan[nx][ny]) {
                    cnt++;
                }
            }
            
            int val = pan[i][j] - cnt;
            if (val > 0) tmp[i][j] = val;
        }
    }
    memcpy(pan, tmp, sizeof(tmp));
    return;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int answer = 0;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> pan[i][j];
        }
    }
    
    while (1) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (pan[i][j] != 0 && !visited[i][j]) {
                    cnt += 1;
                    visited[i][j] = true;
                    DFS(i, j);
                }
            }
        }
        
        if (cnt > 1) {
            break;
        } else if (cnt == 0) {
            answer = 0;
            break;
        }
        
        answer += 1;
        melting();
        memset(visited, 0, sizeof(visited));
        
    }
    
    cout << answer << "\n";
    
    return 0;
}
