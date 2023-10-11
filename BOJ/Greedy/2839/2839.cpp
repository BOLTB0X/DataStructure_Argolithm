// 2830 설탕 배달
// https://www.acmicpc.net/problem/2839
#include <iostream>

using namespace std;

int main(void) {
    int N, answer = 0;

    cin >> N;

    while (N > 0)
    {
        if (N % 5 == 0)
        {
            answer += (N/5);
            break;
        } else {
            N -= 3;
            answer++;
            if (N < 0) answer = -1;
        }
    }

    cout << answer;

    return 0;
}