// 4796 캠핑
// https://www.acmicpc.net/problem/4796
#include <iostream>

using namespace std;

int mn(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 8 5 20
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
    // o o o o o       o  o  o  o  o          o   o  o  o

    int L, P, V, idx = 0;

    while (1)
    {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;
        printf("Case %d: %d\n", ++idx, L * (V / P) + mn((V % P), L));
    }
    

    return 0;
}