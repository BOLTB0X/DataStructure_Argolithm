// 2810 컵홀더
// https://www.acmicpc.net/problem/2810
#include <iostream>

using namespace std;

int main(void) {
    string sit;
    int N, sCnt = 0, lCnt =0;

    cin >> N;
    cin >> sit;

    for (char& ch: sit)
    {
        if (ch == 'S') sCnt++;
        if (ch == 'L') lCnt++;
    }

    if (lCnt && lCnt % 2 == 0)
    {
        lCnt /= 2;
        lCnt++;
    }

    cout << lCnt+sCnt << '\n';
    return 0;
}