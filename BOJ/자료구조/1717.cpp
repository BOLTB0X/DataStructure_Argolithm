// 1717 집합의 표현
// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>

using namespace std;

int nodes[1000001];

int Find(int x) {
    if (nodes[x] != x) nodes[x] = Find(nodes[x]);
    return nodes[x];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a < b) nodes[b] = a;
    else nodes[a] = b;
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) nodes[i] = i;
    for (int i = 0; i < M; ++i) {
        int c, a, b;
        
        cin >> c >> a >> b;

        if (c == 0) {
            Union(a, b);
        } else {
            if (Find(a) == Find(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}