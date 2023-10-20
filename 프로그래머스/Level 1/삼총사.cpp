// https://school.programmers.co.kr/learn/courses/30/lessons/131705
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int res = 0;
vector<int> visited;

void combination(vector<int> number, int tot, int cur, int depth) {
    if (depth == 3)
    {
        if (tot == 0) res++;
        return;
    }
    
    for (int i = cur; i < number.size(); ++i)
    {
        if (visited[i]) continue;
        visited[i] = 1;
        tot += number[i];
        combination(number, tot, i+1, depth+1);
        tot -= number[i];
        visited[i] = 0;
    }
    
    return;
}

int solution(vector<int> number) {
    int answer = 0;
    visited.resize(number.size(), 0);
    
    combination(number, 0, 0, 0);
    answer = res;
    
    return answer;
}