// 4796 캠핑
// https://www.acmicpc.net/problem/4796
#include <cstdio>

int mn(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int L, P, V;
    
    int idx = 1;
    while (1)
    {
        int answer;
        scanf("%d %d %d", &L, &P, &V);

        if (L == 0 && P == 0 && V == 0) break;

        // 캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다. 강산이는 이제 막 V일짜리 휴가를 시작했다. 
        // 강산이가 캠핑장을 최대 며칠동안 사용할 수 있을까?
        // 1 ~ 10 5
        // 

        printf("Case %d: %d\n", idx++, L * (V / P) + mn((V % P), L));
    }
    return 0;
}