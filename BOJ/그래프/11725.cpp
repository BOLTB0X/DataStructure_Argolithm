// 11725 트리의 부모 찾기
// https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int N;
vector<int> Node;
vector<int> adj[MAX];
vector<bool> visited;

void DFS(int cur) {
    visited[cur] = true;
    for (int& next: adj[cur]) {
        if (visited[next]) continue;
        Node[next] = cur;
        DFS(next);
    }
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Node = vector<int> (N+1, 0);
    visited = vector<bool> (N+1, false);

    for (int i = 0; i < N-1; ++i)
    {
        int a, b;

        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1);

    for (int i = 2; i <= N; ++i) cout << Node[i] << '\n';

    return 0;
}