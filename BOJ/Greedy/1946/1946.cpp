// 1946 신입 사원
// https://www.acmicpc.net/problem/1946
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, vector<pair<int,int>> aply) {
    int answer = 1;

// 3 2  1 4  5 5
// 1 4  2 3  4 1
// 4 1  3 2  3 2
// 2 3  4 1  2 3
// 5 5  5 5  1 4

    sort(aply.begin(), aply.end());
    int interviewRank = 0;

    for (int i = 1; i < N; ++i)
    {
        if (aply[interviewRank].second > aply[i].second)
        {
            interviewRank = i;
            answer++;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, N;

    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        vector<pair<int,int>> aply;
        for (int i = 0; i < N; ++i) 
        {
            int a, b;
            cin >> a >> b;
            aply.push_back({a, b});
        }

        cout << solution(N, aply) << '\n';
    }

    return 0;
}