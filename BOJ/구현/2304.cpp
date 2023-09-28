// 2304 창고 다각형
// https://www.acmicpc.net/problem/2304
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<pair<int, int>> Pillar;

int mx(int a, int b) {
    return a > b ? a : b;
}

int solution(void) {
    int answer = 0, maxIdx = 0, maxHeight = 0;
    int pos[1001];

    memset(pos, 0, sizeof(pos));

    for (auto& p: Pillar)
    {
        pos[p.first] = p.second;

        if (p.second > pos[maxIdx])
        {
            maxIdx = p.first;
        }
    }

    for (int i = 1; i <= maxIdx; ++i)
    {
        maxHeight = mx(pos[i], maxHeight);
        answer += maxHeight;
    }

    maxHeight = 0;
    for (int i = 1000; i > maxIdx; --i)
    {
        maxHeight = mx(pos[i], maxHeight);
        answer += maxHeight;
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int L, H;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> L >> H;
        Pillar.push_back({L,H});
    }

    cout << solution();

    return 0;
}