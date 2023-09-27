// 1541 잃어버린 괄호
// https://www.acmicpc.net/problem/1541
#include <iostream>
#include <string>

using namespace std;

int solution(string sik) {
    int answer = 0, flag = 1; // 1이면 + , 0이면 -
    string tmp = "";

    for (char& ch: sik)
    {
        if (ch == '-' || ch == '+')
        {
            if (flag) // + 연산
            {
                answer += stoi(tmp);
            } else {
                answer -= stoi(tmp);
            }
            tmp = "";

            if (ch == '-') flag = 0;
        }
        else tmp += ch;

        
    }

    if (tmp.size() > 0)
    {
        if (flag) answer += stoi(tmp);
        else answer -= stoi(tmp);
    }
    return answer;
}

int main(void)
{
    string inputStr;

    cin >> inputStr;
    cout << solution(inputStr);
    return 0;
}