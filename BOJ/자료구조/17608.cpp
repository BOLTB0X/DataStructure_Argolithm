// 17608 막대기
// https://www.acmicpc.net/problem/17608
#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<int> stack) {
    int answer = 0;

    while (!stack.empty())
    {
        int cur = stack.back();
        stack.pop_back();
        answer++;

        while(!stack.empty() && cur >= stack.back())
            stack.pop_back();
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, val;
    vector<int> stack;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> val;
        stack.push_back(val);
    }

    cout << solution(N, stack);

    return 0;
}