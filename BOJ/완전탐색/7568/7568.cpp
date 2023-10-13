// 7568 덩치
// https://www.acmicpc.net/problem/7568
#include <iostream>
#include <vector>
// 실5
using namespace std;

void solution(int N, vector<pair<int,int>> info) {
    vector<int> answer;

    for (int i = 0; i < info.size(); ++i)
    {
        pair<int,int> cur = info[i];
        int cnt = 1;
        for (int j = 0; j < info.size(); ++j)
        {
            if (i == j) continue;

            if (cur.first < info[j].first && cur.second < info[j].second)
            {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }

    for (int a: answer)
    {
        cout << a << ' ';
    }
    cout << '\n';
    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<pair<int,int>> info;

    cin >> N;
    info = vector<pair<int,int>> (N);
    for (int i = 0; i< N; ++i)
    {
        cin >> info[i].first >> info[i].second;
    }

    solution(N, info);

    return 0;
}