// https://school.programmers.co.kr/learn/courses/30/lessons/142086
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> alp;
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (alp.find(s[i]) != alp.end())
        {
            //cout << s[i] << ' ' << alp[s[i]] << '\n';
            answer.push_back(i-alp[s[i]]);
        } else
        {
            answer.push_back(-1);
        }
        alp[s[i]] = i;
    }
    return answer;
}