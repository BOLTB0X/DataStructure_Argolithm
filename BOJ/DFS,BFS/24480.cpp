// 24480 알고리즘 수업 - 깊이 우선 탐색 2
// https://www.acmicpc.net/problem/24480
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M, R, cnt = 1;
vector<int> adj[MAX];
vector<int> visited;
vector<int> path(MAX, 0);

bool compare(int a, int b) {
    return a > b;
}

void DFS(int cur) {
    visited[cur] = 1;
    path[cur] = cnt++;

    for (int &next: adj[cur])
    {
        if (visited[next]) continue;

        DFS(next);
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    visited = vector<int> (N+1, 0);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) sort(adj[i].begin(), adj[i].end(), compare);

    DFS(R);
    for (int i = 1; i <= N; ++i) cout << path[i] << '\n';

    return 0;
}