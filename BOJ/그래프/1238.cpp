// 1238 파티
// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <vector>
#include <queue>
#define INF 98765432

using namespace std;

int N, M, X;
vector<pair<int,int>> adj[1001];
vector<int> dist;

int mx(int a, int b) {
    return a > b ? a : b;
}

void dijkstra(int start) {
    priority_queue<pair<int,int>> pq;
    dist = vector<int>(N+1, INF);

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curNode = pq.top().second;
        int curCost = -pq.top().first;
        pq.pop();

        if (dist[curNode] < curCost) continue;

        for (auto next: adj[curNode]) {
            int nextNode = next.first;
            int nextCost = next.second;

            if (dist[nextNode] <= nextCost + curCost) continue;

            dist[nextNode] = nextCost + curCost;
            pq.push({-dist[nextNode], nextNode});
        }
    }
    
    return;
}

int solution(void) {
    int answer = 0;

    for (int i = 1; i <= N; ++i) {
        dijkstra(i);
        int cost = dist[X];
        dijkstra(X);
        cost += dist[i];
        answer = mx(answer, cost);
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    cout << solution();

    return 0;
}