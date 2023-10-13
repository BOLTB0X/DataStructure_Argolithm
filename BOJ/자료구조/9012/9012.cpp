// 9012 괄호
// https://www.acmicpc.net/problem/9012
#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "YES";
    vector<int> stack;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            stack.push_back(1);
        } else {
            if (stack.empty()) 
            {
                answer = "NO";
                break;
            }
            stack.pop_back();
        }
    }

    if (!stack.empty()) 
    {
        answer = "NO";
    }

    return answer;
}

int main(void) {
    int T;
    string s;

    cin >> T;
    while (T--)
    {
        cin >> s;
        cout << solution(s) << '\n';
    }
    

    return 0;
}