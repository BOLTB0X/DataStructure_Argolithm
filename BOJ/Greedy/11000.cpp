// 11000 강의실 배정
// https://www.acmicpc.net/problem/11000
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, a, b;
    vector<pair<int,int>> time;
    priority_queue<int> pq;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        time.push_back({a, b});
    }

    sort(time.begin(), time.end());

    for (auto t: time)
    {
        pq.push(-t.second);
        if (t.first >= -pq.top()) pq.pop();
        
    }

    cout << pq.size();

    return 0;
}