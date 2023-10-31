// https://school.programmers.co.kr/learn/courses/30/lessons/155652
#include <string>
#include <vector>

using namespace std;

int contains(string str, char ch) {
    for (char c: str) {
        if (c == ch) return 1;
    }
    return 0;
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for (char ch: s) {
        int val = ch - 'a';
        int cnt = 0;
        
        while (cnt < index) {
            val++;
            if (val > 25) val = 0;
            
            if (contains(skip, val+'a')) continue;
            cnt++;
        }
        answer.push_back(val + 'a');
    }
    
    return answer;
}