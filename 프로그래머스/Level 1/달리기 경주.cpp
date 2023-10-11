// https://school.programmers.co.kr/learn/courses/30/lessons/178871
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> playersMap;
    
    for (int i = 0; i < players.size(); ++i)
    {
        playersMap[players[i]] = i;
    }
    
    for (string c : callings)
    {
        // 현재 불린 선수의 앞에 선수
        string prev = players[playersMap[c]-1];
        
        playersMap[c] -= 1;
        playersMap[prev] += 1;
        
        string tmp =  players[playersMap[c]];
        players[playersMap[c]] = players[playersMap[prev]];
        players[playersMap[prev]] = tmp;
    }
    
    answer = players;
    return answer;
}