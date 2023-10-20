// https://school.programmers.co.kr/learn/courses/30/lessons/49993
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (string cur: skill_trees) {
        queue<char> que;
        int flag = 1; 
        
        for (char sk: skill) que.push(sk);
        
        for (char c: cur) {
            if (skill.find(c) != string::npos) {
                if (que.front() == c) {
                    que.pop();
                } else {
                    flag = 0;
                    break;
                }
            } else {
                continue;
            }
        }
        
        if (flag) 
        {
            //cout << cur << '\n';
            answer++;
        }
    }
    return answer;
}