// https://school.programmers.co.kr/learn/courses/30/lessons/12905
#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> v) {
    int ret = v[0];
    
    for (int i = 1; i < v.size(); ++i) {
        if (ret > v[i]) ret = v[i];
    }
    
    return ret;
}

int solution(vector<vector<int>> board) {
    int answer = board[0][0];
    
    for (int i = 1; i < board.size(); ++i) {
        for (int j = 1; j < board[0].size(); ++j) {
            if (board[i][j] == 1) {
                int tmp = findMin({board[i-1][j], board[i][j-1], board[i-1][j-1]});
                board[i][j] = 1 + tmp;
                answer = answer > board[i][j] ? answer : board[i][j];
            }
        }
    }
    
    // for (int i = 0; i < board.size(); ++i) {
    //     for (int j = 0; j < board[0].size(); ++j) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return answer * answer;
}