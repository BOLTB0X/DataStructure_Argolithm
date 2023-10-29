// 1753 최단 경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <queue>
#include <vector>
#define INF 98765432

using namespace std;

int V, E, K;

vector<pair<int,int>> adj[20001];
vector<int> dist;

void solution(void) {
    priority_queue<pair<int,int>> pq;
    dist.resize(V+1, INF);

    pq.push({0, K});
    dist[K] = 0;

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist) continue;

        for (auto next: adj[curNode]) {
            int nextDist = next.second;
            int nextNode = next.first;

            if (dist[nextNode] <= nextDist + curDist) continue;

            dist[nextNode] = curDist + nextDist;
            pq.push({-dist[nextNode], nextNode});
        }

    }

    for (int i = 1; i <= V; ++i)
    {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;

    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i) {
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    solution();
    return 0;
}