// 1916 최소비용 구하기
// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1001, INF = 1e9;

int N, M;
vector<pair<int,int>> adj[MAX];
int dist[MAX];

int dijkstra(int s, int e) {
  int res = 0;

  for (int i = 1; i <= N; ++i) dist[i] = INF;
  
  priority_queue<pair<int,int>> pq;
  dist[s] = 0;
  pq.push({0, s});

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
  res = dist[e];
  return res;
}

int main(void) {
  int start, end;
  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b,c});
  }

  cin >> start >> end;

  cout << dijkstra(start, end);

  return 0;
}