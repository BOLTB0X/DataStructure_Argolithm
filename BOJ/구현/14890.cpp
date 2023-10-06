// 14890 경사로
// https://www.acmicpc.net/problem/14890
#include <iostream>
#include <vector>

using namespace std;

int board[101][101];

int Abs(int a) {
    return a < 0 ? -a : a;
}

bool isPossible(int N, int L, vector<int> v) {
    vector<bool> visited(N, false);

    for (int i = 1; i < N; ++i)
    {
        if (v[i-1] != v[i]) 
        {
            if (Abs(v[i]-v[i-1]) > 1) return false;

            // 이제부터 경사로 설치
            // i+1가 높은지 낮은지 구분
            if (v[i-1] < v[i])
            {
                for (int l = 1; l <= L; ++l)
                {   
                    // 범위 초과
                    if (i - l < 0) return false;

                    // 높거나 낮아지는 경우
                    if (v[i-1] != v[i-l]) return false;

                    if (visited[i-l]) return false;

                    visited[i-l] = true;
                }
            } else // 낮은 경우
            {
                for (int l = 0; l < L; ++l)
                {
                    if (i + l >= N) return false;

                    if (v[i] != v[i+l]) return false;

                    if (visited[i+l]) return false;

                    visited[i+l] = true;
                }

            }
        }
    }
    return true;
}

int solution(int N, int L) {
    int answer = 0;

    // 경사로는 낮은 칸에 놓으며, L개의 연속된 칸에 경사로의 바닥이 모두 접해야 한다.
    // 낮은 칸과 높은 칸의 높이 차이는 1이어야 한다.
    // 경사로를 놓을 낮은 칸의 높이는 모두 같아야 하고, L개의 칸이 연속되어 있어야 한다.
    // 행부터
    for (int i = 0; i < N; ++i)
    {
        vector<int> row;
        for (int j = 0; j < N; ++j)
        {
            row.push_back(board[i][j]);
        }

        if (isPossible(N, L, row))
        {
            answer++;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        vector<int> col;
        for (int j = 0; j < N; ++j)
        {
            col.push_back(board[j][i]);
        }

        if (isPossible(N, L, col))
        {
            answer++;
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, L;

    cin >> N >> L;
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << solution(N, L);

    return 0;
}