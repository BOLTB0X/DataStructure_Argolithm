#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int V, E, K;
vector<pair<int,int>> adj[20001];
int dist[20001];

void solution(void) {
    priority_queue<pair<int,int>> pq;
    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (int i = 0; i < adj[curNode].size(); ++i) {
            int newNode = adj[curNode][i].first;
            int newDist = adj[curNode][i].second;
            if (newDist + curDist < dist[newNode]) {
                dist[newNode] = newDist + curDist;
                pq.push(make_pair(-dist[newNode], newNode));
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (dist[i] == INF) 
            cout << "INF" << "\n";
        else 
            cout << dist[i] << "\n";
    }
    return;
}

int main(void) {
	//초기화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> V >> E >> K;

    for (int i =0; i <= V; ++i) {
        dist[i] = INF;
    }

    for (int i = 0; i < E; ++i) {
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].push_back(make_pair(y, d));
    }

    solution();
    return 0;
}