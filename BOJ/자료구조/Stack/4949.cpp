// 4949 군형잡힌 세상
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "yes";
    vector<char> stack;
    int flag = 0;

    for (char ch: s)
    {
        if (ch == '(' || ch == '[') stack.push_back(ch);
        
        else if (ch == ')')
        {
            if (!stack.empty() && stack.back() == '(') stack.pop_back();
            else 
            {
                flag = 1;
                break;
            }
        } else if (ch == ']')
        {
            if (!stack.empty() && stack.back() == '[') stack.pop_back();
            else 
            {
                flag = 1;
                break;
            }
        }
    }

    if (flag || !stack.empty()) answer = "no";
    return answer;
}

int main(void) {
    while (1)
    {
        string input;
        getline(cin, input);

        if (input == ".") break;

        cout << solution(input) << '\n';
    }
    

    return 0;
}