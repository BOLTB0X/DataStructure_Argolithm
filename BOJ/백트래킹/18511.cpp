// 18511 큰 수 구성하기
// https://www.acmicpc.net/problem/18511
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K, answer = 0;
int setK[3] = {};

int mx(int a, int b) {
    return a > b ? a : b;
}

void backTracking(vector<int> cur ,int depth, int len) {
    if (depth == len)
    {
        int num = 0;
        for (int& c: cur)
        {
            num += c;
            num *= 10;
        }
        num /= 10;

        if (N >= num) answer = mx(answer, num);
        return;
    }

    for (int i = 0; i < K; ++i)
    {
        cur.push_back(setK[i]);
        backTracking(cur, depth+1, len);
        cur.pop_back();
    }
    return;
}

int main(void) {
    cin >> N >> K;

    for (int i = 0; i < K; ++i)
    {
        cin >> setK[i];
    }

    for (int i = 1; i <= to_string(N).size(); ++i)
        backTracking({}, 0, i);

    cout << answer;
    return 0;
}