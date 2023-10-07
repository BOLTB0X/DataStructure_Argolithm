// 1753 최단경로
// https://www.acmicpc.net/problem/1753
#include <iostream>
#include <vector>
#include <queue>
#define INF 98765432

using namespace std;

vector<pair<int,int>> adj[20001];

void dijktra(int V, int E, int K) {
    int result = 0;

    vector<int> dist(V+1,INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0, K});
    dist[K] = 0;

    while (!pq.empty())
    {
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curCost) continue;

        for (pair<int,int>& next: adj[curNode])
        {
            int nextCost = next.second;
            int nextNode = next.first;

            if (dist[nextNode] <= curCost+nextCost) continue;

            dist[nextNode] = curCost+nextCost;
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
    int V, E, K, a, b, c;

    cin >> V >> E;
    cin >> K;

    for (int i = 0; i < E; ++i)
    {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }


    dijktra(V, E, K);
    return 0;
}