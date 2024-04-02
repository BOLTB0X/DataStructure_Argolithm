// 1874 스택 수열
// https://www.acmicpc.net/problem/1874
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, val, number = 1, flag = 1;
    vector<char> answer;
    vector<int> stack;

    cin >> N;
    while (N--)
    {
        cin >> val;


        while (number <= val)
        {
            answer.push_back('+');
            stack.push_back(number++);
        }

        if (stack.back() < val)
        {
            flag = 0;
            break;
        }
        
        while (stack.back() >= val)
        {
            answer.push_back('-');
            stack.pop_back();
        }
    }

    if (flag)
    {
        for (char a: answer) cout << a << '\n';
    } else
    {
        cout << "NO" << '\n';
    }
    
    return 0;
}