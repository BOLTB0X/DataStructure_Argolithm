// https://school.programmers.co.kr/learn/courses/30/lessons/160586
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    unordered_map<char, int> Hash;
    
    for (string & km: keymap)
    {
        for (int i = 0; i < km.size(); ++i)
        {
            if (Hash.find(km[i]) != Hash.end())
            {
                Hash[km[i]] = min(Hash[km[i]], i+1);
            } else
            {
                Hash[km[i]] = i+1;
            }
        }
    }
    
    // auto it = Hash.begin();
    // while (it != Hash.end())
    // {
    //     cout << it->first << ' ' << it->second << '\n';
    //     it++;
    // }
    
    for (string& target: targets)
    {
        int cnt = 0;
        for (char& t: target)
        {
            if (Hash.find(t) != Hash.end())
                cnt += Hash[t];
            else
            {
                cnt = -1;
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}