// https://school.programmers.co.kr/learn/courses/30/lessons/172927
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Mineral {
    int dia, iron, stone;
    
    bool operator < (const Mineral &A) const {
        if (dia == A.dia)
        {
            if (iron == A.iron)
            {
                return stone > A.stone;
            }
            return iron > A.iron;
        }
        return dia > A.dia;
    }
};

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, pickCount = 0;
    
    // 곡괭이 수
    for (int p: picks)
    {
        pickCount += p;
    }
    
    if (pickCount * 5 < minerals.size())
    {
        for (int i = 0; i < (pickCount * 5) - minerals.size(); ++i)
        {
            minerals.pop_back();
        }   
    }
    
    vector<Mineral> mineralCount(minerals.size()/5+1, {0,0,0});
    
    for (int i = 0; i < minerals.size(); ++i)
    {
        if (minerals[i] == "diamond")
        {
            mineralCount[i/5].dia++;
        } else if (minerals[i] == "iron")
        {
            mineralCount[i/5].iron++;
        } else 
        {
            mineralCount[i/5].stone++;
        }
    }
    
    // for (auto m: mineralCount)
    // {
    //     cout << m.dia << ' ' << m.iron << ' ' << m.stone << '\n';
    // }
    
    sort(mineralCount.begin(), mineralCount.end());
    
    for (auto mCount: mineralCount)
    {
        int dia = mCount.dia, iron = mCount.iron, stone = mCount.stone;
        
        for (int i = 0; i < picks.size(); ++i)
        {
            if (picks[i] > 0 && i == 0)
            {
                picks[i]--;
                answer += (dia+iron+stone);
                break;
            } else if (picks[i] > 0 && i == 1)
            {
                picks[i]--;
                answer += ((5*dia)+iron+stone);
                break;
            } else if (picks[i] > 0 && i == 2)
            {
                picks[i]--;
                answer += ((25*dia)+(5*iron)+stone);
                break;
            }
        }
    }
    
    return answer;
}