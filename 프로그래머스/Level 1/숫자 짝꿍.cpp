// https://school.programmers.co.kr/learn/courses/30/lessons/131128
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(char a, char b) {
    return a > b;
}

string solution(string X, string Y) {
    string answer = "";
    unordered_map<char,int> xMap;
    unordered_map<char,int> yMap;
    vector<char> tmp;
    
    for (char& x: X)
    {
        xMap[x] += 1; 
    }
    
    for (char& y: Y)
    {
        yMap[y] += 1; 
    }
    
    for (auto iter = xMap.begin(); iter != xMap.end(); ++iter)
    {
        if (yMap.find(iter->first) != yMap.end())
        {
            int minCount = min(iter->second, yMap[iter->first]);
            while (minCount--) answer += iter->first;
        }
    }
    
    if (!answer.size()) answer = "-1";
    else
    {
        sort(answer.begin(), answer.end(), compare);
        if (answer[0] == '0') answer = "0";
    }
    
    return answer;
}