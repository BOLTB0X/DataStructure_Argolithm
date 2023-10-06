// https://school.programmers.co.kr/learn/courses/30/lessons/12903?language=python3
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    if (s.size() % 2)
    {
        answer += s[s.size()/2];
    } else
    {
        answer += s[s.size()/2 - 1];
        answer += s[s.size()/2];
    }
    return answer;
}