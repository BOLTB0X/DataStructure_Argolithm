// 17396 백도어
// https://www.acmicpc.net/problem/17396
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001
#define INF 1e12

using namespace std;

int N, M;
vector<pair<int,long long>> adj[MAX];
vector<int> branch;
long long dist[MAX];

long long dijkstra(void) {
  priority_queue<pair<long long,int>> pq;
  for (int i = 0; i < N; ++i) dist[i] = INF;
  
  dist[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    long long curDist = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

    if (curNode == N-1) return dist[curNode];

    if (curDist > dist[curNode]) continue;

    for(auto& next: adj[curNode]) {
      long long nextDist = next.second;
      int nextNode = next.first;
      if (dist[nextNode] > nextDist +curDist) {
        dist[nextNode] = nextDist + curDist;
        pq.push({-dist[nextNode], nextNode});
      }
    }
  }
  return -1;
}

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    branch.push_back(a);
  }

  for (int i = 0; i < M; ++i) {
    int a, b;
    long long c;
    cin >> a >> b >> c;

    if ((!branch[a] && !branch[b]) || (a == N - 1 || b == N- 1)) {
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
    }
  }

  cout << dijkstra();
  return 0;
}