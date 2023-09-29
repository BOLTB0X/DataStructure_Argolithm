// 16943 숫자 재배치
// https://www.acmicpc.net/problem/16943
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int A, B;
int answer = -1;
vector<int> visited;

void permutation(string str_A, string str_B, string cur, int depth) {
    if (depth == str_A.length())
    {
        int intCur = stoi(cur);
        if (intCur != A && B > intCur) 
        {
            answer = answer > intCur ? answer : intCur;
        }
        return;
    }

    for (int i  = 0; i < str_A.length(); ++i)
    {
        if (visited[i]) continue;

        if (!cur.length()&& str_A[i] == '0') continue;

        visited[i] = 1;
        permutation(str_A, str_B, cur+str_A[i], depth+1);
        visited[i] = 0;
    }
    return;
}

int main(void) {
    cin >> A >> B;
    string str_A = to_string(A);
    string str_B = to_string(B);
    
    visited.resize(str_A.length(), 0);
    permutation(str_A, str_B, "", 0);
    
    cout << answer;
    
    return 0;
}
