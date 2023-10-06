// 2745 진법 변환
// https://www.acmicpc.net/problem/2745
#include <iostream>
#include <string>
#define LL long long

using namespace std;

LL solution(string N, int B) {
    LL answer = 0;

    for (int i = N.size()-1, j = 1; i >= 0; --i, j *= B)
    {
        if (N[i] >= 'A' && N[i] <= 'Z')
        {
            answer += (N[i] - 'A' + 10) * j;
        } else
        {
            answer += (N[i] - '0') * j;
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string N;
    int B;

    cin >> N >> B;
    cout << solution(N, B);
    return 0;
}