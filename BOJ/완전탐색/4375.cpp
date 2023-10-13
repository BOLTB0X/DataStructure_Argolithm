// 4375 1
// https://www.acmicpc.net/problem/4375
#include <iostream>
#define LL long long

using namespace std;

LL solution(LL N) {
    LL answer = 1;
    LL number = 1;

    // x mod N = (x mod N) mod N 

    while (1)
    {
        if (number % N == 0) break;

        number %= N;
        number = number * 10 + 1;
        answer++;
    }
    
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    LL N;

    while (cin >> N)
    {
        cout << solution(N) << '\n';
    }
    

    return 0;
}