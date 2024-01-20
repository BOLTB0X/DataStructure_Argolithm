// 1747 소수&팰린드롬
// https://www.acmicpc.net/problem/1747
#include <iostream>
#include <string>
#include <vector>
#define MAX 1003002

using namespace std;

vector<int> prime(MAX, 0);

void eratos(void) {
    prime[0] = prime[1] = 1;

    for (int i = 2; i * i <= MAX; ++i) {
        if (prime[i]) continue;

        for (int j = i + i; j <= MAX; j += i) prime[j] = 1;
    }
    return;
}

bool isPanlindrome(int num) {
    string str = to_string(num);

    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size()-1-i]) return false;
    }

    return true;
}

int solution(int N) {
    int answer;
    
    eratos();

    for (int i = N; i <= MAX; ++i) {
        if (prime[i]) continue;

        if (isPanlindrome(i)) {
            answer = i;
            break;
        }
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    cout << solution(N);

    return 0;
}