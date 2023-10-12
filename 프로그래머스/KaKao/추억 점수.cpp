// https://school.programmers.co.kr/learn/courses/30/lessons/176963
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> hashMap;
    
    for (int i = 0; i < name.size(); ++i)
    {
        hashMap[name[i]] = yearning[i];
    }
    
    for (auto &p: photo)
    {
        int tot = 0;
        for (auto n: p)
        {
            tot += hashMap[n];
        }
        answer.push_back(tot);
    }
    return answer;
}