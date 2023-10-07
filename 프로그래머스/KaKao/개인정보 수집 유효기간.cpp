// https://school.programmers.co.kr/learn/courses/30/lessons/150370
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int vectorString_to_Int(vector<string> v) {
    int ret = (stoi(v[0])*12*28)+(stoi(v[1])*28)+stoi(v[2]);
    return ret;
}

vector<string> split(string s, string ch) {
    vector<string> ret;
    
    while (s.find(ch) != string::npos) 
    {
        int idx = s.find(ch);
        ret.push_back(s.substr(0, idx));
        s = s.substr(idx+ch.length());
    }
    
    ret.push_back(s);
    
    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<string,int> termsMap;
    int Today = vectorString_to_Int(split(today, "."));
    
    for (string& t: terms)
    {
        vector<string> splitedT = split(t, " ");
        termsMap[splitedT[0]] = stoi(splitedT[1]) * 28;
    }
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        vector<string> tmpPri = split(privacies[i], " ");
        int currentDay = vectorString_to_Int(split(tmpPri[0], "."));
        int currentT = termsMap[tmpPri[1]];
        
        //cout << currentDay+currentT << ' ' << Today << '\n';
        if (currentDay + currentT <= Today) {
            answer.push_back(i+1);
        }
    }
    
    return answer;
}