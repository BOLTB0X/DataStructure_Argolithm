// https://school.programmers.co.kr/learn/courses/30/lessons/43105
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mx(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            dp[i][j] = triangle[i][j]+ mx(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    // for (int i = 0; i < size; ++i)
    // {
    //     for (int j = 0; j < size; ++j)
    //     {
    //         if (dp[i][j] != 0)
    //         {
    //             cout << dp[i][j] << ' ';
    //         }
    //     }
    //     cout << '\n';
    // }
    
    for (int i = 0; i < size; ++i)
    {
        answer = mx(answer, dp[size-1][i]);
    }
    
    return answer;
}