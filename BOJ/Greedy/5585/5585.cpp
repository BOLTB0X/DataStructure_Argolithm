// 5585 거스름돈
// https://www.acmicpc.net/problem/5585
#include <cstdio>

int main(void) {
    int moeny, answer = 0;
    int cointype[6] = {500, 100, 50, 10, 5 ,1};

    scanf("%d", &moeny);
    moeny = 1000 - moeny;
    for (int& coin: cointype)
    {
        if (moeny >= coin)
        {
            answer += (moeny / coin);
            moeny %= coin;
            // 3 1 3
        }
    }

    printf("%d", answer);
    return 0;
}