// https://school.programmers.co.kr/learn/courses/30/lessons/178870
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int mindiff = 1e9;
    int seq_total = sequence[0], left = 0, right = 0;
    
    while (left < sequence.size() && right < sequence.size()) 
    {
        if (seq_total == k && mindiff > right-left)
        {
            mindiff = right-left;
            answer = {left, right};
        }
        //cout << left << ' ' << right << '\n';
        if (seq_total > k)
        {
            seq_total -= sequence[left++];
        } else
        {
            ++right;
            if (right >= sequence.size()) continue;
            seq_total += sequence[right];
        }
    }
    return answer;
}