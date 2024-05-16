#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int convert_IntegerTime(string t) {
    return stoi(t.substr(0, 2))*60 + stoi(t.substr(3));
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string, int>> stack;
    int t = 0;
    
    sort(plans.begin(), plans.end(), [](vector<string> a, vector<string> b){
        return a[1] < b[1];
    });
    
    for (auto plan: plans) {
        int curTime = convert_IntegerTime(plan[1]);
        
        while (t < curTime) {
            t++;
            
            if (stack.empty()) { continue; }
            
            stack.back().second--;
            if (stack.back().second == 0) {
                answer.push_back(stack.back().first);
                stack.pop_back();
            }
        }
        
        stack.push_back({plan[0], stoi(plan[2])});
    }
    
    while (!stack.empty()) {
        answer.push_back(stack.back().first);
        stack.pop_back();
    }
    
    return answer;
}