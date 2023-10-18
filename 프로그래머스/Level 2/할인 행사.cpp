// https://school.programmers.co.kr/learn/courses/30/lessons/131127
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> productsMap;
    
    for (int i = 0; i < discount.size() - 9; ++i) {
        for (int i = 0; i < want.size(); ++i) {
            productsMap[want[i]] = number[i];
        }
        
        for (int j = i; j <= i + 9; ++j) {
            if (productsMap.find(discount[j]) != productsMap.end())
                productsMap[discount[j]] -= 1;
        }
        
        int flag = 1;
        for (auto iter = productsMap.begin(); iter != productsMap.end(); ++iter) {
            if (iter->second > 0)
            {
                flag = 0;
                break;
            }
        }
        
        if (flag) answer++;
        productsMap.clear();
    }
    
    return answer;
}