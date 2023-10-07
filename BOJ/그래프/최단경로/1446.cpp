// 1446 지름길
// https://www.acmicpc.net/problem/1446
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> adj[10001];

int dijkstra(int D, int start) {
    vector<int> dist(10001, INF);
    priority_queue<pair<int,int>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curCost > dist[curNode]) continue;

        for (auto& next: adj[curNode])
        {
            int nextCost = next.second;
            int nextNode = next.first;

            if (nextCost+curCost >= dist[nextNode]) continue;

            dist[nextNode] = nextCost+curCost;
            pq.push({-dist[nextNode], nextNode});
        }
    }
    
    return dist[D];
}

int solution(int N, int D) {
    int answer = 0;

    answer = dijkstra(D, 0);
    
    return answer;
}

int main(void) {
    int N, D;

    cin >> N >> D;
    for (int i = 0; i < D; ++i)
    {
        adj[i].push_back({i+1, 1});
    }

    for (int i = 0; i < N; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    cout << solution(N, D);
    return 0;
}