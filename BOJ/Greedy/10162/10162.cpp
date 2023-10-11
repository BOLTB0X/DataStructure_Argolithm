// 10162 전자레인지
// https://www.acmicpc.net/problem/10162
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    vector<int> answer;
    int btn[3] = {300, 60, 10};

    cin >> T;

    for (int i = 0; i < 3; ++i)
    {
        answer.push_back(T / btn[i]);
        T = T % btn[i];
    }

    if (T)
    {
        cout << -1 << '\n';
    } else
    {
        for (int& a: answer)
        {
            cout << a << ' ';
        }
    }

    return 0;
}