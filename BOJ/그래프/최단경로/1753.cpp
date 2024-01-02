// 1753 최단 경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
#define INF 98765432

using namespace std;

int V, E, K;
vector<pair<int,int>> adj[20001];

void dijkstra(void) {
    int answer = 0;
    vector<int> dist(V+1, INF);
    priority_queue<pair<int,int>> pq;

    pq.push({0, K});
    dist[K] = 0;

    while (!pq.empty())
    {
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curCost) continue;

        for (auto next: adj[curNode]) {
            int nextCost = next.second;
            int nextNode = next.first;

            if (dist[nextNode] <= curCost + nextCost) continue;

            dist[nextNode] = curCost + nextCost;
            pq.push({-dist[nextNode], nextNode});
        }
    }
    
    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E >> K;
    for (int i = 0; i < E; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dijkstra();
    return 0;
}