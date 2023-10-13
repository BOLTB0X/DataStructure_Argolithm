// 1158 요세푸스 문제
// https://www.acmicpc.net/problem/1158
#include <iostream>
#include <queue>

using namespace std;

// 1 2 3 4 5 6 7

// 4 5 6 7 1 2 -> 3
// 7 1 2 4 5   -> 6
// 4 5 7 1     -> 2
// 1 4 5       -> 7
// 1 4         -> 5
//             -> 1
//             -> 4

void solution(int N, int K) {
    queue<int> que;
    for (int i = 1; i <= N; ++i) que.push(i);

    cout << "<";
    while (!que.empty())
    {
        int cnt = K - 1;
        while (cnt--)
        {
            que.push(que.front());
            que.pop();
        }
        
        cout << que.front();
        if (que.size() != 1) cout << ", ";
        que.pop();
    }
    cout << ">";

    return;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    solution(N, K);

    return 0;
}