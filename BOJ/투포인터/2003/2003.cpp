// 2003 수들의 합 2
// https://www.acmicpc.net/problem/2003
#include <iostream>
#include <vector>
#define LL long long

using namespace std;

int main(void) {
    int N;
    LL M;
    vector<LL> A;

    cin >> N >> M;
    A = vector<LL> (N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    LL answer = 0;
    LL A_Sum = 0;
    int s = 0, e = 0;

    while (s < N)
    {
        if (A_Sum >= M) {
            A_Sum -= A[s];
            s++;
        } else {
            A_Sum += A[e];
            e++;
        }

        if (A_Sum == M) answer++;
    }

    cout << answer;
    // l:2 r:3 O
    // l:4 r:2
    // 
    // 
    return 0;
}