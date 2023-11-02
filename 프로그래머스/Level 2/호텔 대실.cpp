// https://school.programmers.co.kr/learn/courses/30/lessons/155651?language=cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int str_To_int(string str) {
    string tmp1 = str.substr(0, 2);
    string tmp2 = str.substr(3, 2);
    
    return stoi(tmp1) * 60 + stoi(tmp2);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<int>> book_time_int;
    vector<int> waitting;
    
    for (auto book: book_time) {
        //cout << str_To_int(book[0]) << ' ' << str_To_int(book[1]) << '\n';
        book_time_int.push_back({str_To_int(book[0]), str_To_int(book[1])});
    }
    
    sort(book_time_int.begin(), book_time_int.end());
    waitting.push_back(book_time_int[0][1]);
    
    for (int i = 1; i < book_time_int.size(); ++i) {
        int flag = 0;
        for (int j = 0; j < waitting.size(); ++j) {
            if (waitting[j] + 10 <= book_time_int[i][0]) {
                flag = 1;
                waitting[j] = book_time_int[i][1];
                break;
            }
        }
        
        if (!flag) waitting.push_back(book_time_int[i][1]);
    }
    
    answer = waitting.size();
    return answer;
}