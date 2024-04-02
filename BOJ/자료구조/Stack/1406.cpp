// 1406 에디터
// https://www.acmicpc.net/problem/1406
#include <iostream>
#include <vector>

using namespace std;

string solution(string s, int N, vector<pair<char,char>> cmd) {
    string answer = "";
    int flag = 0;
    vector<char> left;
    vector<char> right;

    // L : a b c d y
    // R : x

    // L: y _
    // R: c b a x 


    for (char ch: s) left.push_back(ch);

    for (auto c: cmd)
    {
        if (c.first == 'P')
        {
            left.push_back(c.second);
        }

        else if (c.first == 'L')
        {
            if (left.empty()) continue;
            
            right.push_back(left.back());
            left.pop_back();
        }
        else if (c.first == 'D')
        {
            if (right.empty()) continue;

            left.push_back(right.back());
            right.pop_back();
        }
        else if (c.first == 'B')
        {
            if (left.empty()) continue;
            left.pop_back();
        }
    }

    for (char l: left) answer += l;
    while (!right.empty())
    {
        answer += right.back();
        right.pop_back();
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    int N;
    
    vector<pair<char,char>> cmd;

    cin >> input;
    cin >> N;
    
    cmd = vector<pair<char,char>> (N);
    for (int i = 0; i < N; ++i)
    {
        char a, b;
    
        cin >> a;
        if (a == 'P')
        {
            cin >> b;
            cmd[i] = {a, b};
        } else 
        {
            cmd[i] = {a, '1'};
        }
    }

    cout << solution(input, N, cmd);

    return 0;
}