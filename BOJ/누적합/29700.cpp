// 29700 우당탕탕 영화예매
// https://www.acmicpc.net/problem/29700
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int N, int M, int K, vector<string> board) {
    int answer = 0;

    // //브루트 포스 시간 초과
    // for (int i = 0; i < N; ++i)
    // {
    //     int cnt = 0;
    //     for (int j = 0; j < M; ++j)
    //     {
    //         if (board[i][j] == '0')
    //         {
    //             cnt++;
    //             if (cnt >= K)
    //             {
    //                 answer++;
    //                 --j;
    //                 cnt = 1;
    //             }
    //         } else {
    //             cnt = 0;
    //         }
    //     }
    // }

    // 누적합 
    vector<vector<int>> prefixSum(N, vector<int>(M, 0));
    // 셋팅
    for (int i = 0; i < N; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == '0')
            {
                cnt++;
            } else 
            {
                cnt = 0;
            }
            prefixSum[i][j] = cnt;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (prefixSum[i][j] >= K) answer++;
        }
        
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N , M, K;
    vector<string> board;

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }

    cout << solution(N, M, K, board);

    return 0;
}