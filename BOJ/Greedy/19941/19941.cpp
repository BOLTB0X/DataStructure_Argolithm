// 19941 햄버거 분배
// https://www.acmicpc.net/problem/19941
#include <iostream>
#include <cstring>

using namespace std;

int N, K;
string info;
int visited[20001];

bool check(int cur) {
    for (int i = -K; i <=K; ++i) {
        if (cur + i < 0 || cur + i >= N) continue;

        if (info[cur+i] == 'H' && !visited[cur + i]) {
            visited[cur+i] = 1;
            return true;
        }
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cin >> info;

    int answer = 0;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; ++i)
    {
        if (info[i] == 'P' && check(i))
        {
           answer++;
        }
    }

    cout << answer << '\n';
    
    return 0;
}