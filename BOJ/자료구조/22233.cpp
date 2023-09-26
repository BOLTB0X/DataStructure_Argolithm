// 22233 가희와 키워드
// https://www.acmicpc.net/problem/22233
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int N, M;
unordered_set<string> keywords;

int solution(string memo) {
    int starIdx = 0;
    
    while (true) 
    {
        int idx = memo.find(",", starIdx);

        if (idx != -1) 
        {
            string m = memo.substr(starIdx, idx-starIdx);

            if (keywords.find(m) != keywords.end()) keywords.erase(m);

            starIdx = idx+1;
        } else {
            string m = memo.substr(starIdx);

            if (keywords.find(m) != keywords.end()) keywords.erase(m);
            break;
        }
    }
    

    return keywords.size();
}

int main(void) {
    cin.tie(NULL); 
    cout.tie(NULL); 
    ios::sync_with_stdio(false);

    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) 
    {
        string input1;
        cin >> input1;

        keywords.insert(input1);
    }

    for (int i = 0; i < M; ++i) 
    {
        string input2;
        cin >> input2;
        int ret = solution(input2);
        printf("%d\n", ret);
    }

    return 0;
}