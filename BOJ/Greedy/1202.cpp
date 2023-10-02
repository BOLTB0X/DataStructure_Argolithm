// 1202 보석 도둑
// https://www.acmicpc.net/problem/1202
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define LL long long

using namespace std;

LL solution(int N, int K, vector<pair<int,int>> bag, vector<int> bagWeight) {
    LL answer = 0, idx = 0;
    priority_queue<int> pq;
    sort(bagWeight.begin(), bagWeight.end());
    sort(bag.begin(), bag.end());

    for (int& weight: bagWeight)
    {
        while(idx < N && weight >= bag[idx].first) 
        {
            pq.push(bag[idx].second);
            idx++;
        }

        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    vector<pair<int,int>> bag;
    vector<int> limitW;

    cin >> N >> K;
    bag = vector<pair<int,int>>(N);
    limitW = vector<int>(K);

    for (int i = 0; i < N; ++i)
    {
        cin >> bag[i].first >> bag[i].second;
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> limitW[i];
    }

    cout << solution(N, K, bag, limitW);

    return 0;
}