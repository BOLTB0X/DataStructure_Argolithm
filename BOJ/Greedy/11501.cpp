// 11501 주식
// https://www.acmicpc.net/problem/11501
#include <iostream>

using namespace std;

int N;
int budgets[1000001];

int mx(int a, int b) {
    return a > b ? a : b;
}

long long solution(void) {
    long long answer = 0;
    long long res = -1;

    for (int i = N-1; i>=0; --i) 
    {
        res = mx(res, budgets[i]);
        answer += (res-budgets[i]);
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL); 

    int T;
    cin >> T;

    while (T) 
    {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> budgets[i];
        cout << solution() << '\n';
        T--;
    }
    return 0;
}