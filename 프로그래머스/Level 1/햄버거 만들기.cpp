// https://school.programmers.co.kr/learn/courses/30/lessons/133502
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> stack;
    
    // 빵 – 야채 – 고기 - 빵
    for (int i: ingredient) {
        stack.push_back(i);
        
        if (stack.size() > 3 && stack[stack.size() - 4] == 1 
            && stack[stack.size() - 3] == 2 && stack[stack.size() - 2] == 3 
           && stack[stack.size() - 1] == 1) {
            answer++;
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
        }
    }
    
    if (stack.size() > 3 && stack[stack.size() - 4] == 1 
        && stack[stack.size() - 3] == 2 && stack[stack.size() - 2] == 3 
        && stack[stack.size() - 1] == 1) {
        answer++;
        stack.pop_back();
        stack.pop_back();
        stack.pop_back();
        stack.pop_back();
    }
    return answer;
}