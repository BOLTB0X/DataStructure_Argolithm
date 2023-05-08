#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string moum = "AEIOU";
vector<string> candi;

void DFS(string cur, int level) {
    if (cur.length() == level) {
        candi.push_back(cur);
        return;
    }

    for (int i = 0; i < 5; ++i) {
        DFS(cur + moum[i], level);
    }
}

int solution(string word) {
    int answer = 0;
    
    for (int i = 1; i <= 5; ++i) {
        DFS("", i);
    }
    
    sort(candi.begin(), candi.end());
    
    for (auto c : candi) {
        if (c == word) 
            break;
        answer++;
    }
    return answer + 1;
}