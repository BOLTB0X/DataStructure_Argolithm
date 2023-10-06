// https://school.programmers.co.kr/learn/courses/30/lessons/155651?language=cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

vector<string> split(string st, string separator) {
    vector<string> tokens;
    string token;
    
    int idx = st.find(separator);
    tokens.push_back(st.substr(0, idx));
    tokens.push_back(st.substr(idx+1));
    
    return tokens;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> room;
    vector<pair<int,int>> integerTime;
    
    for (auto& time: book_time)
    {
        vector<string> front = split(time[0], ":");
        vector<string> back = split(time[1], ":");
        
        integerTime.push_back({stoi(front[0])*60+stoi(front[1]), stoi(back[0])*60+stoi(back[1])});
    }
    
    sort(integerTime.begin(), integerTime.end(), compare);
    
    for (pair<int,int>& t: integerTime)
    {
        if (room.empty()) room.push_back(t);
        else
        {
            int flag = 0;
            for (int i = 0; i < room.size(); ++i)
            {
                if (room[i].second + 10 <= t.first) 
                {
                    flag = 1;
                    room[i] = t;
                    break;
                }
            }
            
            if (!flag) room.push_back(t);
        }
    }
    
    answer = room.size();
    return answer;
}