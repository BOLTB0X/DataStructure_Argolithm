// 1527 금민수의 개수
// https://www.acmicpc.net/problem/1527
#include <iostream>
#include <string>
#define LL long long
using namespace std;

LL A, B, res = 0;

void DFS(LL cur) {
    if (cur > B) return;
    
    if (cur >= A && cur <= B) {
        res++;
    }

    DFS(cur*10+4);
    DFS(cur*10+7);
    return;
}

int main(void) {
    ios:: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
    DFS(4);
    DFS(7);
    cout << res;

    return 0;
}