#include <iostream>
#include <queue>
#include <vector>
#define INF 98765432

using namespace std;

int N, E;
int Node1, Node2;
vector<pair<int, int>> adj[810];
int dist[810];

int mn(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

void dijkstra(int start) {
  priority_queue<pair<int, int>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int curDist = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

    if (dist[curNode] < curDist)
      continue;

    for (int i = 0; i < adj[curNode].size(); ++i) {
      int nextDist = adj[curNode][i].second;
      int nextNode = adj[curNode][i].first;

      if (dist[nextNode] > nextDist + curDist) {
        dist[nextNode] = nextDist + curDist;
        pq.push({-dist[nextNode], nextNode});
      }
    }
  }
  return;
}

void solution(void) {
  int answer;

  // 1 번부터 각 노드 거리
  for (int i = 0; i <= N; ++i)
    dist[i] = INF;
  dijkstra(1);
  int oneToNode1 = dist[Node1];
  int oneToNode2 = dist[Node2];

  // 필수 노드 Node1 Node2 거리
  for (int i = 1; i <= N; ++i)
    dist[i] = INF;
  dijkstra(Node1);

  int Node1ToNode2 = dist[Node2]; // Node1 -> Node2 거리
  int Node1TON = dist[N];         // Node2 -> N

  // 1 -> ... -> Node1 -> .. -> Node2 이므로
  for (int i = 1; i <= N; ++i)
    dist[i] = INF;
  dijkstra(Node2);
  int Node2ToN = dist[N]; // Node2 -> N

  answer = mn(INF, oneToNode1 + Node1ToNode2 + Node2ToN);
  answer = mn(answer, oneToNode2 + Node1ToNode2 + Node1TON);

  if (answer >= INF)
    cout << -1;
  else
    cout << answer;
  return;
}

int main(void) {
  cin >> N >> E;
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    adj[a].push_back(make_pair(b, c));
    adj[b].push_back(make_pair(a, c));
  }

  cin >> Node1 >> Node2;

  solution();
  return 0;
}