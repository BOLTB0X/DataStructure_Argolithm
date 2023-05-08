#include <string>
#include <vector>
#include <cstring>

using namespace std;

int board[101][101];
int visited[101];

int abs(int a) {
    return a < 0 ? -a : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void DFS(int n, int cur, int &cnt) {
    visited[cur] = 1;
    cnt++;
    
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 1)
            continue;
        
        if (board[cur][i] == 0)
            continue;
        
        DFS(n, i, cnt);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n; // 최솟값을 구해야 하므로
    
    for (auto& w : wires) {
        board[w[0]][w[1]] = 1;
        board[w[1]][w[0]] = 1;
    }
    
    for (auto& w : wires) {
        board[w[0]][w[1]] = 0;
        board[w[1]][w[0]] = 0;
        memset(visited, 0, sizeof(visited));
        
        int cnt1 = 0;
        int cnt2 = 0;
        DFS(n, w[0], cnt1);
        DFS(n, w[1], cnt2);
        answer = min(answer, abs(cnt1 - cnt2));
        
        board[w[0]][w[1]] = 1;
        board[w[1]][w[0]] = 1;
    }
    
    return answer;
}