// 1931 회의실 배정
// https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> rooms;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int solution(void)
{
    int answer = 1;

    sort(rooms.begin(), rooms.end(), compare);
    int cmpEndTime = rooms[0].second;

    for (int i = 1; i < rooms.size(); ++i)
    {
        if (cmpEndTime <= rooms[i].first) 
        {
            cmpEndTime = rooms[i].second;
            answer++;
        }
    }

    return answer;
}

int main(void) {
    cin >> N;
    int s, e;

    for (int i = 0; i < N; ++i)
    {
        cin >> s >> e;
        rooms.push_back({s,e});
    }

    cout << solution();
    return 0;
}