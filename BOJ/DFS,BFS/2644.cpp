// 2644 촌수계산
// https://www.acmicpc.net/problem/2644
#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

int N, M;
int t1, t2, res = -1;
vector<int> adj[MAX];
vector<int> visited;
vector<int> Node;

void DFS(int cur, int target, int depth) {
    visited[cur] = 1;

    for (int& next: adj[cur]) {
        if (visited[next]) continue;

        if (next == target) 
        {
            res = depth;
            return;
        }

        DFS(next, target, depth+1);
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> t1 >> t2;
    cin >> M;

    Node = vector<int> (N+1, 0);
    visited = vector<int> (N+1 , 0);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(t1, t2, 1);

    cout << res;

    return 0;
}