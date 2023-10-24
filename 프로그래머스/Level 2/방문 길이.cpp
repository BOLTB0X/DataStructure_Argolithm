// https://school.programmers.co.kr/learn/courses/30/lessons/49994
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<pair<pair<int, int>, pair<int, int>>, bool> visited;

int solution(string dirs) {
    int answer = 0;
    int cx = 5, cy = 5;
    
    for (int i = 0; i < dirs.size(); ++i) {
        int sx = cx, sy = cy;
        if (dirs[i] == 'U') {
            if (cx - 1 >= 0) cx--;
            else continue;
        } else if (dirs[i] == 'D') {
            if (cx + 1 <= 10) cx++;
            else continue;
        } else if (dirs[i] == 'R') {
            if (cy + 1 <= 10) cy++;
            else continue;
        } else {
            if (cy - 1 >= 0) cy--;
            else continue;            
        }
        if (visited[{{sx, sy}, {cx, cy}}] == true) continue;
        
        visited[{{sx, sy}, {cx, cy}}] = true;
        visited[{{cx, cy}, {sx, sy}}] = true;
        answer++;
    }
    return answer;
}