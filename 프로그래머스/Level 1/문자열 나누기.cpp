// https://school.programmers.co.kr/learn/courses/30/lessons/140108
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<char> stack;
    stack.push_back(s.front());
    
    for (int i = 1; i < s.size(); ++i) {
        if (stack.empty()) {
            stack.push_back(s[i]);
        } else {
            if (stack.back() == s[i]) stack.push_back(s[i]);
            else stack.pop_back();
        }
        
        if (stack.empty()) answer++;
    }
    
    if (!stack.empty()) answer++;
    
    return answer;
}