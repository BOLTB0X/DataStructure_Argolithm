// 1527 금민수의 개수
// https://www.acmicpc.net/problem/1527
#include <iostream>

using namespace std;

long long res = 0;

void DFS(long long number1, long long number2, long long cur)
{
    if (cur > number2) return;

    if (cur >= number1 && cur <= number2) res++;

    DFS(number1, number2, cur*10+4);
    DFS(number1, number2, cur*10+7);
    return;
}

int main(void) {
    long long A, B;

    cin >> A >> B;

    DFS(A, B, 4);
    DFS(A, B, 7);

    cout << res;
    return 0;
}