//
//  main.cpp
//  13023 ABCDE
//  https://www.acmicpc.net/problem/13023
//  Created by KyungHeon Lee on 2023/09/19.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[2001];
vector<int> visited(2001, 0);
int flag = 0;

void DFS(int N, int cur, int depth) {
    if (depth == 4) {
        flag = 1;
        return;
    }
    
    for (auto & next : adj[cur]) {
        if (visited[next]) {
            continue;
        }
        
        visited[next] = 1;
        DFS(N, next, depth+1);
        visited[next] = 0;
    }
}

int solution(int N, int M, vector<pair<int, int>> arr) {
    for (auto & a: arr) {
        adj[a.first].push_back(a.second);
        adj[a.second].push_back(a.first);
    }
    
    for (int i = 0; i < N; ++i) {
        visited[i] = 1;
        DFS(N, i , 0);
        visited[i] = 0;
        
        if (flag) {
            break;
        }
    }
    return flag == 1 ? 1 : 0;
}


int main(int argc, const char * argv[]) {
    int N, M;
    vector<pair<int, int>> arr;
    
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    
    cout << solution(N, M, arr) << "\n";
    return 0;
}
