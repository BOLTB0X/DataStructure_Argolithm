// 1922 네트워크 연결
// https://www.acmicpc.net/problem/1922
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

struct Info {
    int cost, x, y;

    bool operator < (const Info& i) const {
        return cost < i.cost;
    }
};

int N, M, answer;
int parent[MAX];
vector<Info> edge;

int Find(int x) {
    if (x != parent[x]) return parent[x] = Find(parent[x]);
    return x;
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
    return; 
}

bool isSameParent(int a, int b) {
    return Find(a) == Find(b);
}

int solution(void) {
    int answer = 0;

    sort(edge.begin(), edge.end());

    for (int i = 0; i <= N; ++i) parent[i] = i;

    for (int i = 0; i < M; ++i) {
        if (!isSameParent(edge[i].x, edge[i].y)) {
            Union(edge[i].x, edge[i].y);
            answer += edge[i].cost;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }

    cout << solution();
    return 0;
}