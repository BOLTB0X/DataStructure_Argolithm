// 2022 KAKAO TECH INTERNSHIP 성격 유형 검사하기
// https://school.programmers.co.kr/learn/courses/30/lessons/118666
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<string> jipyos = {"RT", "CF", "JM", "AN"};
    unordered_map<char,int> typeDic = {{'R', 0}, {'T', 0}, {'C', 0}, {'F', 0},
                                      {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}};
    int score[8] = { 0, 3, 2, 1, 0, 1, 2, 3 };
    
    for (int i = 0; i < survey.size(); ++i) {
        if (choices[i] > 4) {
            typeDic[survey[i][1]] += score[choices[i]];
        } else {
            typeDic[survey[i][0]] += score[choices[i]];
        }
    }
    
    // for (auto iter = typeDic.begin(); iter != typeDic.end(); ++iter) {
    //     cout << iter->first << ' ' << iter->second << '\n';
    // }
    
    for (string jipyo: jipyos) {
        if (typeDic[jipyo[0]] >= typeDic[jipyo[1]])
            answer += jipyo[0];
        else answer += jipyo[1];
    }

    return answer;
}