// 1051 숫자 정사각형
// https://www.acmicpc.net/problem/1051
#include <iostream>
#include <string>

using namespace std;

int mn(int a, int b) {
    return a < b ? a : b;
}

int solution(int N, int M, string *square) {
    int answer = 0;

    int maxLen = 0;
    int len = min(N, M);

    for (int l = 0; l < len; ++l)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (i + l >= N || j + l >= M) continue;

                if (square[i + l][j] == square[i][j] && square[i][j + l] == square[i + l][j]
                    && square[i + l][j] == square[i + l][j + l]) {
                        maxLen = l;
                    }
            }
        }
    }

    answer = (maxLen + 1) * (maxLen + 1); 

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    string square[50];

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> square[i];
    }

    cout << solution(N, M, square);

    return 0;
}
