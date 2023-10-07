// 1373 2진수 8진수
// https://www.acmicpc.net/problem/1373
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string X) {
    string answer = "";

    if (X == "0") return "0";

    int size = X.size();

    if (size % 3 == 1) cout << X[0];
    else if (size % 3 == 2)
    {
        cout << (X[0] - '0') * 2 + (X[1] - '0');
    }

    for (int i = size % 3; i < size; i += 3) 
    {
        cout << (X[i] - '0') * 4 + (X[i+1] - '0') * 2 + (X[i+2] - '0'); 
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string X;
    cin >> X;

    cout << solution(X);
    return 0;
}