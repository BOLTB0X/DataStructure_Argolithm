// 1715 카드 정렬하기
// https://www.acmicpc.net/problem/1715
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int N, vector<int> cards) {
    int answer = 0;
    priority_queue<int> pq;

    for (int &c: cards) pq.push(-c);

    while (pq.size() > 1)
    {
        int fir = -pq.top();
        pq.pop();

        if (pq.empty()) break;

        int sec = -pq.top();
        pq.pop();

        answer += (fir+sec);
        pq.push(-(fir+sec));
    }
    

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<int> cards;

    cin >> N;
    cards = vector<int>(N, 0);

    for (int i = 0; i < N; ++i) cin >> cards[i];

    cout << solution(N, cards);

    return 0;
}