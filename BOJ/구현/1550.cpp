// 1550 16진수
// https://www.acmicpc.net/problem/1550
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string X;
    int answer = 0;
    cin >> X;

    for (int i = X.size()-1, j = 1; i >= 0; --i, j *= 16)
    {
        if (X[i] >= 'A')
        {
            answer += (X[i] - 'A' + 10) * j;
        } else 
        {
            answer += (X[i] - '0') * j;
        }
    }

    cout << answer;

    return 0;
}