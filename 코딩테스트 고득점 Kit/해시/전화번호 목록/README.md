# 고득점 kit > 해시 > 전화번호 목록

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42577
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

다른 것도 있네
<br/>

## 풀이(해쉬)

딕셔니리의 key value를 알면 됌
<br/>

> 전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
> <br/>
> 전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.
> <br/>

해쉬(딕셔너리)에 넣어 두고 폰 번호를 하나씩 더해지는 형태로 해쉬맵에 있는지 체크 히면 됌
<br/>

```python
for phone in phone_book:
    prefix = ""
    for num in phone:
        prefix += num

        if prefix in hashMap and prefix != phone:
            return False
```

<br/>

## 풀이(정렬)

phone_book을 정렬한 뒤, phone_book[i]와 phone_book[i+1]의 상단이 같을 때 바로 False
<br/>

```swift
phone_book.sort{$0.count < $1.count}

for i in 0..<phone_book.count {
    for j in i+1..<phone_book.count {
        // hasPrefix: String(문자열)이 지정된 접두사로 시작하는지 여부를 Boolean 값으로 반환
        if phone_book[j].hasPrefix(phone_book[i]) {
            return false
        }
    }
}
```

<br/>

## 최종 코드

스위프트

```swift
import Foundation

func solution(_ phone_book: [String]) -> Bool {
    var phone_book = phone_book // 편의용
    // 오름차순 정렬
    phone_book.sort{$0.count < $1.count}

    // 완전탐색으로 풀이
    for i in 0..<phone_book.count {
        for j in i+1..<phone_book.count {
            // hasPrefix: String(문자열)이 지정된 접두사로 시작하는지 여부를 Boolean 값으로 반환
            if phone_book[j].hasPrefix(phone_book[i]) {
                return false
            }
        }
    }
    return true
}
```

<br/>

C++

```cpp
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
```

<br/>

파이썬

```python
def solution(phone_book):
    hashMap = {}

    for phone in phone_book:
        hashMap[phone] = 1

    for phone in phone_book:
        prefix = ""
        for num in phone:
            prefix += num

            if prefix in hashMap and prefix != phone:
                return False
    return True

```
