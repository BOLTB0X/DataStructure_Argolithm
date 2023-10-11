// 1946 신입 사원
// https://www.acmicpc.net/problem/1946
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int,int> a, const pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int solution(int N, vector<pair<int,int>> aply) {
    int answer = 1;
    int cmp = 0; // 기준인 넘
    
    sort(aply.begin(), aply.end(), compare);
    cmp = aply.front().second;

    for (int i = 1; i < aply.size(); ++i)
    {
        // 서류는 떨어져도 면접 등수가 높다면
        if (cmp > aply[i].second)
        {
            answer++;
            cmp = aply[i].second;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    vector<pair<int,int>> aply;
    cin >> T;

    while (T--)
    {
        cin >> N;
        aply = vector<pair<int,int>>(N);
        for (int i = 0; i < N; ++i)
            cin >> aply[i].first >> aply[i].second;

        cout << solution(N, aply) << '\n';
    }

    return 0;
}