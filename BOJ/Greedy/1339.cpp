// 1339 단어 수학
// https://www.acmicpc.net/problem/1339
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(int N, vector<string> V) {
    int answer = 0;
    int alp[26];

    memset(alp, 0, sizeof(alp));

    for (string &v: V)
    {
        int pow = 1;
        for (int i = v.size()-1; i >= 0; --i)
        {
            alp[v[i]-'A'] += pow;
            pow *= 10;
        }
    }

    sort(alp, alp+26, compare);

    int number = 9;
    for (int& a: alp)
    {
        if (a == 0) break;
        answer += a*number--;
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    vector<string> v;
    // F: 1
    // C: 10
    // G: 100
    // B: 1
    // E: 10
    // D: 100
    // C: 1000
    // A: 10000
    cin >> N;
    v = vector<string>(N, "");
    for (int i = 0; i < N; ++i) cin >> v[i];

    cout << solution(N, v);

    return 0;
}