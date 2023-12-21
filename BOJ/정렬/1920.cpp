// 1920 수 찾기
// https://www.acmicpc.net/problem/1920
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, target;
    vector<int> v;

    cin >> N;
    v.resize(N, 0);

    for (int& vv: v) cin >> vv;

    sort(v.begin(), v.end());
    
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> target;
        cout << binary_search(v.begin(), v.end(), target) << '\n';
    }

    return 0;
}