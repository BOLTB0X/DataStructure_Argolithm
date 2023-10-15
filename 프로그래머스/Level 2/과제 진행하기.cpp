// https://school.programmers.co.kr/learn/courses/30/lessons/176962
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
    string name;
    int start;
    int used;
};

bool compare(vector<string> a,vector<string> b) {
    return a[1] < b[1];
}

int getMinute(vector<string> h) {
    return stoi(h[0]) * 60 + stoi(h[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Info> watingRoom;
    
    sort(plans.begin(), plans.end(), compare);
    int t = 0;
    
    for (auto& plan: plans)
    {
        int curTime = getMinute({plan[1].substr(0,3), plan[1].substr(3,5)});
        //cout << curTime << '\n';
        while (t < curTime)
        {
            if (!watingRoom.empty()) 
            {
                watingRoom.back().used--;
                if (watingRoom.back().used == 0)
                {
                    answer.push_back(watingRoom.back().name);
                    watingRoom.pop_back();
                }
            }
            t++;
        }
        watingRoom.push_back({plan[0], curTime, stoi(plan[2])});
    }
    
    while (!watingRoom.empty())
    {
        answer.push_back(watingRoom.back().name);
        watingRoom.pop_back();
    }
    
    
    return answer;
}