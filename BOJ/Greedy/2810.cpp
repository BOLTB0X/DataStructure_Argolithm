// 2810 컵홀더
// https://www.acmicpc.net/problem/2810
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, answer;
    string sit;

    cin >> N >> sit;
    int sCnt = 0, lCnt = 0;

    for (char s: sit) {
        if (s == 'S') sCnt++;
        else lCnt++;
    }

    answer = sCnt + (lCnt / 2);
    if (lCnt > 0) {
        answer += 1;
    }

    cout << answer;

    return 0;
}