// 1436 영화감독 숌
// https://www.acmicpc.net/problem/1436
#include <iostream>

using namespace std;

bool isSixSixSix(string s) {
    for (int i = 0; i < s.size()-2; ++i)
    {
        if (s[i] == '6' && s[i+1] == '6' && s[i+2] == '6') return true;
    }
    return false;
}

int main(void) {
    int N, cnt = 0, number = 666;
    string answer;
    cin >> N;

    while (1)
    {
        //cout << cnt << ' ' << number << '\n';
        if (isSixSixSix(to_string(number))) cnt++;

        if (cnt == N) break;
        number++;
    }

    answer = to_string(number);

    cout << answer;
    
    return 0;
}