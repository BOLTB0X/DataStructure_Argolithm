// https://school.programmers.co.kr/learn/courses/30/lessons/169199
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int solution(vector<string> board) {
    int answer = -1;
    int N = board.size(), M = board[0].size();
    vector<vector<int>> visited(board.size(), vector<int> (board[0].size(), 10001));
    queue<pair<int,int>> que;
    
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == 'R')
            {
                visited[i][j] = 0;
                que.push({i, j});
                break;
            }
        }
    }
    
    while (!que.empty())
    {
        int cx = que.front().first;
        int cy = que.front().second;
        //cout << cx << ' ' << cy << '\n';
        que.pop();
        
        if (board[cx][cy] == 'G')
        {
            answer = visited[cx][cy];
            break;
        }
        
        for (auto &d: dir)
        {
            int nx = cx, ny = cy;
            while (1)
            {
                nx += d[0];
                ny += d[1];
                
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                {
                    nx -= d[0];
                    ny -= d[1];
                    //cout << nx << ' ' << ny << '\n';
                    break;
                }
                
                if (board[nx][ny] == 'D')
                {
                    nx -= d[0];
                    ny -= d[1];
                    //cout << nx << ' ' << ny << '\n';
                    break;
                }
            }
            
            if (visited[nx][ny] > visited[cx][cy])
            {
                visited[nx][ny] = visited[cx][cy] + 1;
                que.push({nx, ny});
            }
        }
    }
    
    return answer;
}