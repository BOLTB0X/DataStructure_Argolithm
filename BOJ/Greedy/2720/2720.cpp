// 2720 세탁소 사장 동혁
// https://www.acmicpc.net/problem/2720
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int C) {
    vector<int> answer;
    int Quarters[4] = {25, 10, 5, 1};

    for (int i = 0; i < 4; ++i) 
    {
        answer.push_back(C / Quarters[i]);
        C %= Quarters[i];
    }

    return answer;
}

int main(void) {
    int T, C;

    cin >> T;
    for (int t = 0; t < T; ++t) 
    {
        cin >> C;
        vector<int> ret = solution(C);
        for (auto &r: ret)
        {
            cout << r << ' ';
        }
        cout << '\n';
    }
    return 0;
}