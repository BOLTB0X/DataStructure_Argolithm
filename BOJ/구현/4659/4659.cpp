// 4659 비밀번호 발음하기
// https://www.acmicpc.net/problem/4659
#include <iostream>

using namespace std;

char moum[5] = {'a', 'e', 'i', 'o', 'u'};

bool contains(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

// 1번 조건
bool firstCheck(string inputStr) {
    for (char &s: inputStr) {
        if (contains(s)) return true;
    }
    return false;
}

// 2번 조건
bool secondCheck(string inputStr) {
    // 모음 검사

    for (int i = 0; i < inputStr.size() - 2; ++i) {
        if (contains(inputStr[i]) && contains(inputStr[i+1]) && contains(inputStr[i+2])) {
            return false;
        }
    }

    for (int i = 0; i < inputStr.size() - 2; ++i) {
        if (!contains(inputStr[i]) && !contains(inputStr[i+1]) && !contains(inputStr[i+2])) {
            return false;
        }
    }

    return true;
}

// 3번 조건
bool thridCheck(string inputStr) {
    for (int i = 0; i < inputStr.size()-1; ++i) {
        if (inputStr[i] == inputStr[i+1]) {
            if (inputStr[i] == 'o' || inputStr[i] == 'e') continue;
            return false;
        }
    }
    return true;
}

int main(void) {
    string inputStr;

    while (1) {
        cin >> inputStr;

        if (inputStr == "end") break;

        if (inputStr.size() == 1 || (firstCheck(inputStr) && secondCheck(inputStr) && thridCheck(inputStr)))
            cout << "<" << inputStr << ">" << " is acceptable.\n";
        else
            cout << "<" << inputStr << ">" << " is not acceptable.\n";
    }
    return 0;
}