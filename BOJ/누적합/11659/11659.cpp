// 11659 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    vector<int> v;

    cin >> N >> M;
    v.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }

    vector<int> suffixSum(N, 0);
    suffixSum = v;

    for (int i = 1; i < N; ++i) suffixSum[i] += suffixSum[i-1];

    for (int i = 0; i < M; ++i)
    {
        int s, e;

        cin >> s >> e;
        cout << suffixSum[e-1] - suffixSum[s-2] << '\n';
    }
    
    return 0;
}