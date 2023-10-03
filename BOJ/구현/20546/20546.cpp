// 20546 기적의 매매법
// https://www.acmicpc.net/problem/20546
#include <iostream>

using namespace std;

int money;
int budget[14];

string solution(void) {
    string answer = "";
    int junhyunMoney = money, sungminMoney = money;
    int junhyunBudget = 0, sungminBudget = 0;

    // BNP
    for (int i = 0; i < 14; ++i)
    {
        if (junhyunMoney >= budget[i])
        {
            junhyunBudget += (junhyunMoney/budget[i]);
            junhyunMoney %= budget[i];
        }
    }

    junhyunMoney += budget[13] * junhyunBudget;

    // 타이밍
    for (int i = 3; i < 14; ++i)
    {
        if (budget[i-3] < budget[i-2] && budget[i-2] < budget[i-1] && budget[i-1] < budget[i])
        {
            if (sungminBudget > 0) 
            {
                sungminMoney += (budget[i] * sungminBudget);
                sungminBudget = 0;
            }
        }

        else if (budget[i-3] > budget[i-2] && budget[i-2] > budget[i-1] && budget[i-1] > budget[i])
        {
            if (sungminMoney >= budget[i])
            {
                sungminBudget += (sungminMoney / budget[i]);
                sungminMoney %= budget[i];
            }
        }
    }

    sungminMoney += (budget[13] * sungminBudget);

    //cout << junhyunMoney << ' ' << sungminMoney << '\n';
    if (junhyunMoney > sungminMoney) answer = "BNP";
    else if (junhyunMoney < sungminMoney) answer = "TIMING";
    else answer = "SAMESAME";
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> money;
    for (int i = 0; i < 14; ++i)
    {
        cin >> budget[i];
    }

    cout << solution();
    return 0;
}