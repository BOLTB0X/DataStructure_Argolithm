// 1388 바닥 정식
// https://www.acmicpc.net/problem/1388
// 완전탐색
// DFS
#include <iostream>
#include <vector>

using namespace std;

bool visited[50][50];

int AtypeCheck(int N, int M, vector<string> board) {
    // '-' 검사
    int ret = 0;
    for (int i = 0; i < N; ++i)
    {
        int cnt = 0;
        vector<char> stack;
       for (int j = 0; j < M; ++j)
       {
            if (!stack.empty() && stack.back() != board[i][j]) 
            {
                stack.clear();
                cnt++;
            }
            if (board[i][j] == '-')
            {
                stack.push_back(board[i][j]);
            } 
       }

       if (!stack.empty()) cnt++;
       ret += cnt;
    }
    return ret;
}

int BtypeCheck(int N, int M,  vector<string> board) {
    // '|' 검사
    int ret = 0;
    for (int i = 0; i < M; ++i)
    {
        int cnt = 0;
        vector<char> stack;
       for (int j = 0; j < N; ++j)
       {
            if (!stack.empty() && stack.back() != board[j][i]) 
            {
                stack.clear();
                cnt++;
            }
            if (board[j][i] == '|')
            {
                stack.push_back(board[j][i]);
            } 
       }

       if (!stack.empty()) cnt++;
       ret += cnt;
    }
    return ret;
}

void DFS(int N, int M, int x, int y, vector<string> board) {
    visited[x][y] = true;

    if (board[x][y] == '-')
    {
        if (y + 1 < M && board[x][y] == board[x][y+1]) DFS(N, M, x, y+1, board);
    }

    if (board[x][y] == '|')
    {
        if (x + 1 < N && board[x][y] == board[x+1][y]) DFS(N, M, x+1, y, board);
    }

    return;
}

int solution(int N, int M, vector<string> board) {
    int answer = 0;

    // 완전탐색 풀이
    // cout << AtypeCheck(N, M, board) << '\n';
    // cout << BtypeCheck(N, M, board) << '\n';

    //answer = AtypeCheck(N, M, board) + BtypeCheck(N, M, board);

    // DFS
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (visited[i][j]) continue;

            DFS(N, M, i, j, board);
            answer++;
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    vector<string> board;
    string tmp;

    cin >> N >> M;
    //board = vector<vector<char>> (N, vector<char>(M));

    for (int i = 0; i < N; ++i)
    {
        cin >> tmp;
        board.push_back(tmp);
    }

    cout << solution(N, M, board);
    return 0;
}