// 2810 컵홀더
// https://www.acmicpc.net/problem/2810
#include <iostream>

using namespace std;

int main(void) {
    int N, flag = 0;
    double answer = 0;
    string s;

    cin >> N;
    cin >> s;

    for (char& ch: s)
    {
        if (ch == 'S') answer++;
        else
        {
            flag = 1;
            answer += 0.5;
        }
    }

    if (flag) answer++;
    cout << (int)answer;

    return 0;
}