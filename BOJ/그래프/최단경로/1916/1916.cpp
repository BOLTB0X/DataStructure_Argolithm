// 1916 최소비용 구하기
// https://www.acmicpc.net/problem/1916
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> adj[20001];

int dijkstra(int N, int M, int A, int B) {
    vector<int> dist(N+1,  INF);
    priority_queue<pair<int,int>> pq;
    dist[A] = 0;
    pq.push({0, A});

    while (!pq.empty())
    {
        int curDist = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist) continue;

        for (auto& next: adj[curNode])
        {
            int nextDist = next.second;
            int nextNode = next.first;

            if (dist[nextNode] <= nextDist+curDist) continue;

            dist[nextNode] = nextDist+curDist;
            pq.push({-dist[nextNode], nextNode});
        }
    }
    

    return dist[B];
}

int solution(int N, int M, int A, int B) {
    int answer = 0;
    answer = dijkstra(N, M , A, B);

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, A, B;

    cin >> N >> M;
    int a,b,c;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    cin >> A >> B;
    cout << solution(N, M, A, B);

    return 0;
}