// 1446 지름길
// https://www.acmicpc.net/problem/1446
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 10001, INF = 1e9;

int N, D;
vector<pair<int,int>> adj[MAX];
int dist[MAX];

int dijkstra(void) {
  int res = 0;

  for (int i = 0; i < MAX; ++i) dist[i] = INF;
  
  priority_queue<pair<int,int>> pq;
  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    int curDist = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

    if (curDist > dist[curNode]) continue;

    for (auto& next: adj[curNode]) {
      int nextDist = next.second;
      int nextNode = next.first;

      if (nextDist + curDist < dist[nextNode]) {
        dist[nextNode] = nextDist + curDist;
        pq.push({-dist[nextNode], nextNode});
      }
    }
  }
  res = dist[D];
  return res;
}

int main(void) {
  cin >> N >> D;

  for (int i = 0; i <= D - 1; i++)
		adj[i].push_back({ i+1, 1 });

  for (int i = 0; i < N; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b,c});
  }

  cout << dijkstra();

  return 0;
}