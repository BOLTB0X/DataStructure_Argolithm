// https://school.programmers.co.kr/learn/courses/30/lessons/150368?language=cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int discount[4] = {10, 20, 30, 40};
vector<vector<int>> perArr;

// 중복순열
void backTracking(vector<int> per, int k, int level) {
    if (level == k) 
    {
        perArr.push_back(per);
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        per.push_back(discount[i]);
        backTracking(per, k, level+1);
        per.pop_back();
    }
    return;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer = {0, 0};
    backTracking({}, emoticons.size(), 0);
    
    for(auto& per: perArr)
    {
        int plusAply = 0;
        int sumMoney = 0;
        
        for (auto& user: users) 
        {
            int money = 0;
            for (int i = 0; i < emoticons.size(); ++i)
            {
                if (user[0] > per[i]) continue;
                money += emoticons[i] - emoticons[i]/100 * per[i];
            }
            
            if (money >= user[1])
            {
                plusAply++;
                money = 0;
            }
            sumMoney += money;
        }
        
        //cout << plusAply << ' ' << sumMoney << '\n';
        if (plusAply >= answer[0])
        {
            if (plusAply > answer[0])
            {
                answer[0] = plusAply;
                answer[1] = sumMoney;
            } else
            {
                answer[1] = max(answer[1], sumMoney);
            }
        }
    }
    
    return answer;
}