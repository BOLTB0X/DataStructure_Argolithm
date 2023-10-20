// 1325 효율적인 해킹
// https://www.acmicpc.net/problem/1325
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> adj[10001];
int visited[10001];
int cnt = 0;

void DFS(int cur) {
    visited[cur] = 1;
    cnt++;

    for (int next: adj[cur]) {
        if (visited[next]) continue;
        DFS(next);
    }
    return;
}

void solution(void) {
    vector<int> answer;
    vector<pair<int,int>> Node;

    for (int i = 1; i <= N; ++i) {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        
        DFS(i);

        Node.push_back({i, cnt});
    }

    int maxCnt = 0;
    for (auto n: Node) {
        //cout << n.first << ' ' << n.second << '\n';
        if (maxCnt < n.second)
        {
            maxCnt = n.second;
            answer.clear();
            answer.push_back(n.first);
        } else if (maxCnt == n.second) answer.push_back(n.first);
    }

    for (int a: answer) cout << a << ' ';
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        //adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solution();

    return 0;
}