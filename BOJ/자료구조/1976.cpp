// 1976 여행 가자
// https://www.acmicpc.net/problem/1976
#include <iostream>

using namespace std;

int N, M;
int adj[201][201];
int parent[201];
int plans[1001];

int Find(int x) {
    if (parent[x] != x) return parent[x] = Find(parent[x]);
    return x;
}

void Union(int a, int b) {
    a = Find(parent[a]);
    b = Find(parent[b]);

    if (a < b) parent[b] = a;
    else parent[a] = b;
    return;
}

void solution(void) {
    string answer = "YES";

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (adj[i][j]) Union(i, j);
        }
    }

    for (int i = 1; i < M; ++i) {
        if (Find(plans[i-1]) != Find(plans[i])) {
            answer = "NO";
            break;
        }
    }

    //for (int i = 0; i <= N; ++i) cout << parent[i] << '\n';

    cout << answer;
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i <= N; ++i) parent[i] = i;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < M; ++i) cin >> plans[i];

    solution();
    return 0;
}