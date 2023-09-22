// 파티 1238
// https://www.acmicpc.net/problem/1238
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
#define INF 1e9

using namespace std;

int N, M, X;
vector<pair<int,int>> adj[MAX];
int dist[MAX];

int mx(int a, int b) { 
  return a > b ? a : b;
}

void dijkstra(int start) {
  priority_queue<pair<int,int>> pq;
  for (int i = 1; i <= N; ++i) dist[i] = INF;
  
  dist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int curDist = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

    if (curDist > dist[curNode]) continue;

    for(auto& next: adj[curNode]) {
      int nextDist = next.second;
      int nextNode = next.first;
      if (dist[nextNode] > nextDist +curDist) {
        dist[nextNode] = nextDist + curDist;
        pq.push({-dist[nextNode], nextNode});
      }
    }
  }
  return;
}

void solution(void) {
  int answer = 0;

  for (int i=1; i <= N; ++i) {
    int iTime = 0;
    dijkstra(i);
    iTime += dist[X];
    dijkstra(X);
    iTime += dist[i];
    
    answer = mx(answer, iTime);
  }

  cout << answer;
  return;
}

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  cin >> N >> M >> X;

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back({b, c});
  }

  solution();

  return 0;
}