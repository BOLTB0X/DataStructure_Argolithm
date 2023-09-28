// 1406 에디터
// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <vector>

using namespace std;

string solution(string texts, int N, vector<pair<char, char>> cmds) {
    string answer = "";
    vector<char> leftStack;
    vector<char> rightStack;

    // a b c d y
    // x

    // x : l
    // c b a : r

    // y : l
    // c b a x : r

    for (auto& t: texts)
    {
        leftStack.push_back(t);
    }

    for (auto& cmd: cmds)
    {
        if (cmd.first == 'P')
        {
            leftStack.push_back(cmd.second);
        } else if (cmd.first == 'L')
        {
            if (!leftStack.empty())
            {
                rightStack.push_back(leftStack.back());
                leftStack.pop_back();
            } 
        } else if (cmd.first == 'D')
        {
            if (!rightStack.empty())
            {
            leftStack.push_back(rightStack.back());
            rightStack.pop_back();
            }
        } else if (cmd.first == 'B')
        {
            if (!leftStack.empty())
            {
                leftStack.pop_back();
            }
        }
    }

    for (char& l : leftStack)
    {
        answer += l;
    }

    while (!rightStack.empty())
    {
        answer += rightStack.back();
        rightStack.pop_back();
    }

    return answer;
}

int main(void) {
    string texts;
    int N;
    vector<pair<char,char>> cmds;

    cin >> texts;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        char a,b;
        cin >> a;

        if (a == 'P') 
        {
            cin >> b;
            cmds.push_back({a, b});
        } else 
        {
            cmds.push_back({a, '1'});
        }
    }

    cout << solution(texts, N, cmds);
    
    return 0;
}
