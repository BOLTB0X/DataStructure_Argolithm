// 19532 수학은 비대면강의입니다
// https://www.acmicpc.net/problem/19532
#include <iostream>

using namespace std;

int main(void) {
    pair<int,int> answer = {0, 0};
    int a, b, c, d, e, f;
    int flag = 0;

    cin >> a >> b >> c >> d >> e >> f;

    for (int i = -999; i<= 999; ++i)
    {
        for (int j = -999; j <= 999; ++j)
        {
            if ((a * i + b * j == c) && (d * i + e * j == f))
            {
                answer.first = i, answer.second = j;
                flag = 1;
                break;
                
            }
        }
        if (flag) break;
    }

    cout << answer.first << ' ' << answer.second;
    return 0;
}