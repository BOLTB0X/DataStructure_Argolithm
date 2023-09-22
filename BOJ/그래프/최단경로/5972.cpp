// 5972 택배 배송
// https://www.acmicpc.net/problem/5972
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int MAX = 50001, INF = 1e9;

int N, M;
vector<pair<int, int>> adj[MAX];
int dist[MAX];

int dijkstra(void) {
  int res = INF;

  for (int i = 1; i <= N; ++i)
    dist[i] = INF;

  priority_queue<pair<int, int>> pq;
  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    int curDist = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

    if (curDist > dist[curNode])
      continue;

    for (auto &next : adj[curNode]) {
      int nextDist = next.second;
      int nextNode = next.first;

      if (nextDist + curDist < dist[nextNode]) {
        dist[nextNode] = nextDist + curDist;
        pq.push({-dist[nextNode], nextNode});
      }
    }
  }
  res = dist[N];
  return res;
}

int main(void) {
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  cout << dijkstra();

  return 0;
}