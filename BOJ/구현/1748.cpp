// 1748 수 이어 쓰기 1
// https://www.acmicpc.net/problem/1748
# include <iostream>

using namespace std;

int main(void) {
    int N, answer = 0, i = 1;

    cin >> N;

    while (i <= N)
    {
        answer += (N -i + 1);
        // 15
        // 15 + 6

        i *= 10;
    }

    cout << answer << '\n';
    
    return 0;
}