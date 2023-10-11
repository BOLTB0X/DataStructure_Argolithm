// 1541 잃어버린 괄호
// https://www.acmicpc.net/problem/1541
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, flag = 0;
    vector<int> plusStack;
    vector<int> minusStack;
    string tmp = "";

    for (char &ch: s)
    {
        if (ch >= '0' && ch <= '9')
            tmp += ch;
        else
        {
            if (flag)
            {
                minusStack.push_back(stoi(tmp));
            } else 
            {
                plusStack.push_back(stoi(tmp));
            }
            tmp = "";
            if (ch == '-') flag =1;
        }
    }

    if (flag)
    {
        minusStack.push_back(stoi(tmp));
    } else 
    {
        plusStack.push_back(stoi(tmp));
    }

    int pSum = 0, mSum = 0;
    while (!plusStack.empty())
    {
        pSum += plusStack.back();
        plusStack.pop_back();
    }

    while (!minusStack.empty())
    {
        mSum += minusStack.back();
        minusStack.pop_back();
    }
    
    //cout << pSum << ' ' << mSum << '\n';
    answer = pSum-mSum;
    return answer; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    cout << solution(s);

    return 0;
}