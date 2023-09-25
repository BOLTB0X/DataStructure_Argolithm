// 1244 스위치 켜고 끄기
// https://www.acmicpc.net/problem/1244
#include <iostream>

using namespace std;

int N, M;
int swichs[101];

void switchMen(int num) {
    for (int i = num; i <= N; i += num) {
        swichs[i] = swichs[i] ? 0 : 1;
    }
    return;
}

void switchWomen(int num) {
    swichs[num] = swichs[num] ? 0 : 1;

    for (int i = 1; i <= N/2; ++i) {
        if (num - i < 1 || num + i > N) break;
        if (swichs[num - i] == swichs[num + i]) {
            swichs[num-i] = swichs[num-i] ? 0 : 1;
            swichs[num+i] = swichs[num+i] ? 0 : 1;

        } else {
            break;
        }
    }


    return;
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> swichs[i];
    }

    cin >> M;
    while (M) {
        int a, b;
        cin >> a >> b;
        if (a == 1) { // 남자
        switchMen(b);
        } else { // 여자
        switchWomen(b);
        }
        M--;
    }
    for (int i = 1; i <= N; ++i) {
        cout << swichs[i] << ' ';
        if (i % 20 == 0) {
            cout << "\n";
        }
    }
    return 0;
}