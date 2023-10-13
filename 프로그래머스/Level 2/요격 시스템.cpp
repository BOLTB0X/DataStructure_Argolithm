// https://school.programmers.co.kr/learn/courses/30/lessons/181188
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), [&](vector<int> &v1, vector<int> &v2) {
		return v1[1] < v2[1];
	});
    
    // for (auto t: targets) cout << t[0] << ' ' << t[1] << '\n';
    
    int cur = targets[0][1];
    for (int i = 1; i < targets.size(); ++i)
    {
        if (cur <= targets[i][0])
        {
            cur = targets[i][1];
            answer++;
        }
    }
    
    return answer;
}