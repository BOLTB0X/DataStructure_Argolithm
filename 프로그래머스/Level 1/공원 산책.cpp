// https://school.programmers.co.kr/learn/courses/30/lessons/172928
#include <iostream>
#include <string>
#include <vector>

using namespace std;

pair<int,int> find_StartPosition(vector<string> park) {
    pair<int,int> ret;
    for (int i = 0; i < park.size(); ++i)
    {
        for (int j = 0; j < park[i].size(); ++j)
        {
            if (park[i][j] == 'S')
            {
                return {i, j};
            }
        }
    }
    return ret;
}

int checkDir(char c) {
    if (c == 'N') return 0;
    else if (c == 'S') return 1;
    else if (c == 'W') return 2;
    else return 3;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int,int> cur = find_StartPosition(park);
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (string& route: routes)
    {
        int d = checkDir(route[0]);
        int dist = route[2] - '0';
        
        int nx = cur.first;
        int ny = cur.second;
        
        for (int i = 0; i < dist; ++i)
        {
            nx += dir[d][0];
            ny += dir[d][1];
            
            if (nx < 0 || ny < 0 || nx >= park.size() || ny >= park[0].size())
            {
                nx = cur.first;
                ny = cur.second;
                break;
            }
            
            if (park[nx][ny] == 'X')
            {
                nx = cur.first;
                ny = cur.second;
                break;
            }
            
            //cout << nx << ' ' << ny << '\n';
        }
            
        cur = make_pair(nx, ny);
    }
    
    answer.push_back(cur.first);
    answer.push_back(cur.second);
    return answer;
}