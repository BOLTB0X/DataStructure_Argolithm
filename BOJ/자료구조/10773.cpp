// 10773 제로
// https://www.acmicpc.net/problem/10773
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K, val, answer = 0;
    vector<int> stack;

    cin >> K;
    while (K--)
    {
        cin >> val;
        if (val > 0) {
            stack.push_back(val);
        } else
        {
            if (stack.empty()) continue;
            stack.pop_back();
        }
    }
    
    while (!stack.empty())
    {
        answer += stack.back();
        stack.pop_back();
    }

    cout << answer;

    return 0;
}