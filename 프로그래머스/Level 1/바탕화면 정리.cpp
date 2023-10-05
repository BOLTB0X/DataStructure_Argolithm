// https://school.programmers.co.kr/learn/courses/30/lessons/161990?language=cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mx(int a, int b) {
    return a > b ? a : b;
}

int mn(int a, int b) {
    return a < b ? a : b;
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {2522, 2522, -2522, -2522};
    
    for (int i = 0; i < wallpaper.size(); ++i) 
    {
        for (int j = 0; j < wallpaper[0].size(); ++j)
        {
            if (wallpaper[i][j] == '#')
            {
                answer[0] = mn(answer[0], i);
                answer[1] = mn(answer[1], j);
                answer[2] = mx(answer[2], i+1);
                answer[3] = mx(answer[3], j+1);
            }
        }
    }
    
    return answer;
}