// https://school.programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int answer = 1;
    string stack = "";
    
    for (char ch: s) {
        if (stack.size() && stack.back() == ch) {
            stack.pop_back();
        } else stack.push_back(ch);
    }
    
    answer = stack.size() ? 0 : 1;

    return answer;
}