// 3986 좋은 단어
// https://www.acmicpc.net/problem/3986
#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<string> docum) {
    int answer = 0;

    for (string d: docum)
    {
        vector<char> stack;
        for (int i = 0; i < d.size(); ++i)
        {
            if (!stack.empty() && stack.back() == d[i]) {
                stack.pop_back();
            } else
            {
                stack.push_back(d[i]);
            }
        }

        if (stack.empty()) answer++;

    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<string> docum;

    cin >> N;
    docum = vector<string> (N);
    for (int i = 0; i < N; ++i) cin >> docum[i];

    cout << solution(N, docum);

    return 0;
}