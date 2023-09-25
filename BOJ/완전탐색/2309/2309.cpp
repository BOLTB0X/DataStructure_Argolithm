// 1654 일곱 난쟁이
// https://www.acmicpc.net/problem/2309
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int heights[9];

    for (int i = 0; i <9; ++i) {
        scanf("%d",&heights[i]);
    }

    sort(heights, heights+9);

    int heights_Sum = 0, flag = 0;
    for (int &h: heights) heights_Sum += h;

    for (int i = 0; i < 8; ++i) {
        for (int j = i+1; j <9; ++j) {
            if (heights_Sum - heights[i] - heights[j] == 100) {
                flag = 1;
                heights[i] = -1;
                heights[j] = -1;
            }
        }

        if (flag) break;
    }

    for (int &h: heights) {
        if (h == -1) continue;
        printf("%d\n", h);
    }

    return 0;
}