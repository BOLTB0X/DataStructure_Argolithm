// 1157 단어 공부
// https://www.acmicpc.net/problem/1157
#include <iostream>
#include<cstring>
#include <map>

using namespace std;

// 배열 풀이
char solutionArray(string input) {
  // 일반 배열 이용
  char answer = '?';
  int alp[26];
  int flag = 0;
  int maxCnt = 0;

  memset(alp, 0, sizeof(alp));

  for (auto &i : input) {
    if ((i >= 'A') && (i <= 'Z')) {
      alp[i-'A'] += 1;
      maxCnt = alp[i-'A'] > maxCnt ? alp[i-'A'] : maxCnt;

    } else {
      alp[i-'a'] += 1;
      maxCnt = alp[i-'a'] > maxCnt ? alp[i-'a'] : maxCnt;

    }
  }

  for (int i = 0; i < 26; ++i) {
    if (!flag && alp[i] == maxCnt) {
      answer = i + 'A';
      flag = 1;
    } else if (flag && alp[i] == maxCnt) {
      answer = '?';
      break;
    }
  }
  return answer;
}

// 해쉬 맵으로 풀이
char solutionHash(string input) {
  char answer = '?';
  int maxCount = 0;
  bool flag = true;
  map<char, int> alp;

  for (char &i : input) {
    if (i >= 'a' && i <= 'z') {
      alp[i - 32] += 1; // toupper도 가능
      maxCount = maxCount < alp[i - 32] ? alp[i - 32] : maxCount;
    } else {
      alp[i] += 1;
      maxCount = maxCount < alp[i] ? alp[i] : maxCount;
    }
  }

  for (const auto& a: alp) {
    if (flag && a.second == maxCount) { 
      answer = a.first;
      flag = false;
    } else if (!flag && a.second == maxCount) {
      answer = '?';
      break;
    }
  }

  return answer;
}

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  string input;
  cin >> input;
  
  //cout << solutionArray(input);
  cout << solutionHash(input);
  return 0;
}