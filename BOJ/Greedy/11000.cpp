// 11000 강의실 배정
// https://www.acmicpc.net/problem/11000
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int,int>> room;

int solution(void) {
    int answer = 1;
    priority_queue<int> pq;
    sort(room.begin(), room.end());
    pq.push(-room[0].second);

    for (int i = 1; i < room.size(); ++i)
    {
        pq.push(-room[i].second);
        if (-pq.top() <= room[i].first) {
            pq.pop();
        }
    }

    answer = pq.size();
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        room.push_back({a, b});
    }

    cout << solution();
    return 0;
}