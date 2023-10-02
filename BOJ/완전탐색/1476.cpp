// 1476 날짜 계산
// https://www.acmicpc.net/problem/1476
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19
    int E, S, M, answer = 1;
    cin >> E >> S >> M;

    while (1)
    {
        if ((answer - E) % 15 == 0 && (answer - S) % 28 == 0 && (answer - M) % 19 == 0) break;

        answer++; 
    }

    cout << answer << '\n';
    
    return 0;
}