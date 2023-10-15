// https://school.programmers.co.kr/learn/courses/30/lessons/161989
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int maxSection = 0;
    
    for (int & sec: section)
    {
        if (sec < maxSection) continue;
        
        answer++;
        maxSection = sec+m;
    }
    
    return answer;
}