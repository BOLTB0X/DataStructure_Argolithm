//
//  main.cpp
//  20310 타노스
//  https://www.acmicpc.net/problem/20310
//  Created by KyungHeon Lee on 2023/09/20.
//

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    string S, answer;
    int zCnt = 0, oCnt = 0;
    bool removed[501];
    memset(removed, 0, sizeof(removed));
    cin >> S;
    
    for (auto & s: S) {
        if (s == '1') oCnt++;
        else zCnt++;
    }
    
    oCnt /= 2;
    zCnt /= 2;
    
    int idx = S.size()-1;
    while (zCnt) {
        if (S[idx] == '0') {
            removed[idx] = true;
            zCnt--;
        }
        idx--;
    }

    idx = 0;
    while (oCnt) {
        if (S[idx] == '1') {
            oCnt--;
            removed[idx] = true;
        }
        idx++;
    }

    for (int i = 0; i < S.size(); ++i)
        if (!removed[i]) { answer += S[i]; }
    
    cout << answer << "\n";
    return 0;
}
