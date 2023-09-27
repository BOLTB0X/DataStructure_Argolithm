// 5585 거스름돈
// https://www.acmicpc.net/problem/5585
#include <iostream>

using namespace std;

int main(void)
{
    int money, answer = 0;
    int types[6] = {500, 100, 50, 10, 5, 1};

    cin >> money;
    
    money = 1000 - money;
    for(int& t: types)
    {
        if (t > money) continue;

        answer += (money / t);
        money %= t;
    }
    cout << answer;

    return 0;
}