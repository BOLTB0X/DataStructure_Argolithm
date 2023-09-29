// 11660 구간 합 구하기 5
// https://www.acmicpc.net/problem/11660
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    v = vector<vector<int>> (N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> prefixSum(N+1, vector<int>(N+1, 0));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            prefixSum[i][j] = v[i-1][j-1] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }
    int sx, sy, ex, ey;
    for (int i = 0; i < M; ++i)
    {
        cin >> sx >> sy >> ex >> ey;
        cout << prefixSum[ex][ey] - prefixSum[sx-1][ey]-prefixSum[ex][sy-1]+prefixSum[sx-1][sy-1] << '\n';
    }
    return 0;
}