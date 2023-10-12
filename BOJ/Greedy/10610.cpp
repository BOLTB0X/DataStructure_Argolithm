// 10610 30
// https://www.acmicpc.net/problem/10610
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const char a, const char b) {
    return a > b;
}

string solution(string N) {
    string answer = "-1";

    // 십의 자리 수 A의 배수이기 위해서는
    // 1. 끝의 자리수가 A의 끝자리
    // 2. 각 자리의 수의 합이 A의 십자리 숫자의 배수.

    int tot = 0;
    for (char ch: N) tot += (ch -'0');
    sort(N.begin(), N.end(), compare);

    if (N[N.length()-1] == '0' && tot % 3 == 0)
    {
        answer = N;
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string N;
    cin >> N;
    cout << solution(N);

    return 0;
}