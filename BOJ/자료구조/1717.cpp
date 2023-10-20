// 1717 집합의 표현
// https://www.acmicpc.net/problem/1717
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> nodes;

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

    int a, b, c;

    cin >> N >> M;

    nodes.push_back(0);
    for (int i = 0; i < N; ++i) {
        nodes.push_back(i+1);
    }

    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;

        if (a == 0)
        {
            Union(b, c);
        } else {
            if (Find(b) == Find(c)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}