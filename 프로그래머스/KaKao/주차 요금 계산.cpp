// https://school.programmers.co.kr/learn/courses/30/lessons/92341
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

unordered_map<string,int> inPark;
unordered_map<string,int> prefixSum;

int time_TO_int(vector<string> s) {
    return stoi(s[0])*60 + stoi(s[1]);
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

int getFee(vector<int> f ,int time) {
    int ret = 0;
    int basicM = f[0], basicF = f[1], unitM = f[2], unitF = f[3];
    
    if (basicM >= time) return basicF;
    int tmp = ceil((double)(time - basicM)/unitM);
    //cout << tmp << '\n';
    ret = basicF + tmp * unitF;
    return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for (string& record: records)
    {
        vector<string> r = split(record, " ");
        
        if (r[2] == "IN") // 들어온 경우
        {
            inPark[r[1]] = time_TO_int(split(r[0], ":"));
        } else // 나가는 경우 번호 당 현재까지 금액 업데이트
        {
            int o = time_TO_int(split(r[0], ":")); // 나가는 시간
            int i = inPark[r[1]];
            
            auto it = prefixSum.find(r[1]);
            
            if (it != prefixSum.end())
            {
                prefixSum[r[1]] += (o-i);
            } else
            {
                prefixSum[r[1]] = (o-i);
            }
            
            inPark.erase(r[1]);
        }
    }
    
    for (auto it = inPark.begin(); it != inPark.end(); ++it) 
    {
        string carNumber = it->first;
        int minute = time_TO_int(split("23:59", ":")) - it->second;
        auto i = prefixSum.find(carNumber);
        if (i != prefixSum.end())
        {
           prefixSum[carNumber] += minute;
        } else
        {
           prefixSum[carNumber] = minute;
        }
        
        //cout << carNumber << ": " << prefixSum[carNumber] << '\n';
    }
    
    // for (auto it = prefixSum.begin(); it != prefixSum.end(); ++it)
    // {
    //     cout << it->first << ": " << it->second << '\n';
    // }
    
    vector<pair<string, int>> tmp;
    for (auto it = prefixSum.begin(); it != prefixSum.end(); ++it)
    {
        tmp.push_back({it->first, getFee(fees, it->second)});
    }
    
    sort(tmp.begin(), tmp.end());
    for (auto& t: tmp)
    {
        answer.push_back(t.second);
    }
    
    return answer;
}