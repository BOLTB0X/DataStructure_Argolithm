#include <string>
#include <vector>
#include <unordered_map> // 해쉬이용

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> hash;
    
    // 돌면서 해쉬에 체크
    for (auto book: phone_book) {
        hash[book] = 1;
    }
    
    // 단순풀이
    for (auto book: phone_book) {
        string tmp = "";
        for (int i = 0; i < book.size(); ++i) {
            tmp += book[i];
            // 해쉬에 체크 되어있고 접두사를 찾아야하므로
            if (hash[tmp] == 1 && tmp != book) {
                return false; // 하나라도 있으면
            }
        }
    }
    return answer;
}