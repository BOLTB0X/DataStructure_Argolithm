// 17828 문자열 화폐
// https://www.acmicpc.net/problem/17828
#include <iostream>
#include <string>

using namespace std;

int mn(int a, int b) {
    return a < b ? a : b;
}

string bruteforce(int N, int X) {
    string answer = "";
    int alp = 26;

    if (N * 26 < X || N > X) answer = "!";

    // 64
    // 63 A 63 <= 5*26 
    // 62 A 62 <= 4*26
    // 61 A 61 <= 3*26
    // 60 A 60 <= 2*26 X

    // 브루트 포스
    // 하나씩 알파벳으로 뺀 후, 알파벳으로 표현 가능한지 체크 
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= 26; ++j)
        {
            if (X - j <= (N - i) * 26)
            {
                X -= j;
                answer += (j - 1 + 'A');
                break;
            }
        }
    }
    return answer;
}

string solution(int N, int X) {
    string answer = "";
    int alp = 26;

    if (N * 26 < X || N > X) 
    answer = "!";

    // 64
    // 63 A 63 <= 5*26 
    // 62 A 62 <= 4*26
    // 61 A 61 <= 3*26
    // 60 A 60 <= 2*26 X

    // 그리디
    // 다 A로 셋팅 후, 맨 뒤에서 그리디 진행
    else {
        for (int i = 1; i <= N; ++i) answer += "A";
    
        X -= N;

        for (int i = N -1; i >= 0; --i)
        {
            int tmp = mn(X, 25);
            answer[i] += (tmp);
            X -= tmp;
            if (X <= 0) break;
        }
    }
    
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, X;

    cin >> N >> X;
    cout << solution(N, X) << '\n';

    return 0;
}