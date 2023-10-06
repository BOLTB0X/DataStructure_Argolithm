// 11816 8진수, 10진수, 16진수
// https://www.acmicpc.net/problem/11816
#include <iostream>
#include <string>

using namespace std;

bool is_Decimal(char c) {
    if (c >= '1' && c <= '9') return true;
    return false;
}

bool is_Hex(char c) {
    if (c == 'x') return true;
    return false;
}

int solution(string X) {
    int answer = 0;

    if (is_Decimal(X[0])) // 10
    {
        answer = stoi(X);
    }
    else if (is_Hex(X[1])) // 16
    {
        X.erase(0, 2);
        for (int i = X.size()-1, j = 1; i >= 0; --i, j *= 16)
        {
            if (X[i] >= 'a')
            {
                answer += (X[i] - 'a' + 10) * j;
            } else 
            {
                answer += (X[i]-'0')*j;
            }
        }

    } else // 8
    {
        X.erase(0, 1);
        for (int i = X.size()-1, j = 1; i >= 0; --i, j *= 8)
        {
            answer += (X[i]-'0')*j;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string X;
    cin >> X;

    cout << solution(X);

    return 0;
}