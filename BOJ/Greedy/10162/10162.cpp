// 10162 전자레인지
// https://www.acmicpc.net/problem/10162
#include <iostream>

using namespace std;

int sec[3] = {300, 60, 10};

int main(void) {
    int T;
    int answer[3] = {0, 0, 0};

    cin >> T;

    for (int i = 0; i < 3; ++i)
    {
        if (sec[i] > T)
        {
            continue;
        }

        answer[i] = T / sec[i];
        T %= sec[i];
    }

    if (T) 
        cout << "-1\n";
    else 
    {
        for (int i = 0; i < 3; ++i)
        {
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}