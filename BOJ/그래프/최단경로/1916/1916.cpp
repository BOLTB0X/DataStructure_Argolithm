// 1916 최소비용 구하기
// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> adj[20001];
vector<int> dist;

int dijkstra(int N, int S, int E) {
    int ret = 0;
    priority_queue<pair<int,int>> pq;

    pq.push({0, S});
    dist[S] = 0;

    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist) continue;

        for (auto next: adj[curNode]) {
            int nextDist = next.second;
            int nextNode = next.first;

            if (dist[nextNode] <= curDist + nextDist) continue;

            dist[nextNode] = curDist + nextDist;
            pq.push({-dist[nextNode], nextNode});
        }
    }
    
    ret = dist[E];
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, S, E, a, b, c;

    cin >> N >> M;
    dist = vector<int> (N+1, INF);
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    cin >> S >> E;

    cout << dijkstra(N, S, E);

    return 0;
}