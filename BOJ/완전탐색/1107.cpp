// 1107 리모컨
// https://www.acmicpc.net/problem/1107
#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;

int N, M;
vector<int> visited(MAX, 1);

int mn(int a, int b) {
    return a < b ? a : b;
}

int ABS(int a) {
    return a < 0 ? -a: a;
}

int is_BrokenButton(int b) { // 1이면 고장
    if (!b && !visited[b]) return 1;
    
    while (b > 0)
    {
        int r = b % 10;
        if (!visited[r]) return 1;

        b /= 10;
    }
    
    return 0;
}


int solution(void) {
    int answer = ABS(N-100);

    for (int i = 0; i < MAX; ++i)
    {
        if (!is_BrokenButton(i))
        {
            answer = mn(ABS(N-i) + to_string(i).size(), answer);
        }
    }
    return answer;
}

int main(void) {
    cin >> N;
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int a;
        cin >> a;
        visited[a] = 0; // 고장처리
    }
    
    cout << solution();
    return 0;
}