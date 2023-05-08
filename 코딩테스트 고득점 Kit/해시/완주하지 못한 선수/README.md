# 고득점 kit > 해시 > 완주하지 못한 선수

## 문제

Level 1
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42576
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

딕셔너리 새로운 표현 습득
<br/>

## 풀이

딕셔니리의 key value를 알면 됌
<br/>

key = 참가자 이름을 두고 value에 1로 표시
<br/>

```swift
// 참가자륵 딕셔너리에 넣어줌
for p in participant {
    // 있다면
    if let _ = dict[p] {
        dict[p] = dict[p]! + 1 // 카운트
    } else { // 딕셔너리의 key중에 없다면
        dict[p] = 1
    }
}
```

<br/>

이제 완주자를 이름을 딕셔너리 key에 해당하는 것으로 빼주면 됌
<br/>

여기서 동명이인있어도 동명이인 둘다 했든 못했든 정답은 한명을 리턴하는 거라 괜찮
<br/>

```swift
// 이제 완주를 위 방식처럼 빼주면 그만
for c in completion {
    dict[c] = dict[c]! - 1
}
```

마지막으로 value기준으로 오름차순 정렬하여 마지막원소만 정답으로 반환하면 됌
<br/>

```swift
let arr = dict.sorted(by: {$0.value < $1.value})
answer = arr.last!.key
```

## 최종 코드

스위프트

```swift
import Foundation

func solution(_ participant: [String], _ completion: [String]) -> String{
    var answer:String = ""
    var dict:[String:Int] = [:] // 사용할 딕셔너리

    // 참가자륵 딕셔너리에 넣어줌
    for p in participant {
        // 있다면
        if let _ = dict[p] {
            dict[p] = dict[p]! + 1 // 카운트
        } else { // 딕셔너리의 key중에 없다면
            dict[p] = 1
        }
    }

    // 이제 완주를 위 방식처럼 빼주면 그만
    for c in completion {
        dict[c] = dict[c]! - 1
    }

    // 딕셔너리 value 기준으로 오름차순 정렬
    let arr = dict.sorted(by: {$0.value < $1.value})
    answer = arr.last!.key
    return answer
}
```

<br/>

C++

```cpp
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> hash;
    for (auto p : participant) {
        if (hash.end() == hash.find(p))
            hash.insert(make_pair(p, 1));
        else
            hash[p]++;
    }

    for (auto c : completion) {
        hash[c]--;
    }

    for (auto p : participant) {
        if (hash[p] > 0) {
            answer = p;
            break;
        }
    }
    return answer;
}
```

<br/>
