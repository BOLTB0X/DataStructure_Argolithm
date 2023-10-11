// 19941 햄버거 분배
// https://www.acmicpc.net/problem/19941
#include <iostream>
#include <vector>

using namespace std;

int solution(int N, int K, string s) {
    int answer = 0;
    vector<int> visited(N, 0);

    for (int i = 0; i < N; ++i)
    {
        if (s[i] == 'P')
        {
            int flag = 0;
            for (int j = i-K; j <= i+K; ++j)
            {
                if (j >= 0 && j < N && !visited[j] && s[j] == 'H')
                {
                    visited[j] = 1;
                    flag = 1;
                    break;
                }
            }

            if (flag) answer++;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    string s;
    
    cin >> N >> K;
    cin >> s;

    cout <<  solution(N, K, s);

    return 0;
}