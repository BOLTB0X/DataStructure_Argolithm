# 고득점 kit > 완전탐색 > 모의고사

## 문제

Level 1
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42840
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

진짜 단순 완전탐색문제
<br/>

## 풀이

단순한 완전탐색문제임
<br/>

문제를 풀어나갈때 신경을 써야할 점은 딱 2가지임
<br/>

1. **_수포자 별 찍는 방식을 고려한 인덱스 처리_**

> 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
> <br/>
> 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
> <br/>
> 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
> <br/>

문제 설명에서 알수 있듯히 수포자들간에 찍는 패턴이 있음

```swift
let supoja1:[Int] = [1,2,3,4,5] // 길이 5
let supoja2:[Int] = [2,1,2,3,2,4,2,5] // 길이 8
let supoja3:[Int] = [3,3,1,1,2,2,4,4,5,5] // 길이 10
```

이렇게 찍는 패턴을 배열로 나타내고 for문으로 정답을 하나씩 확인할 때

```swift
for i in answers.enumerated() {
    // 현재 답이 수포자1과 같다면
    if i.1 == supoja1[i.0 % supoja1.count] {
        totalAns[0] += 1
    }
    // 현재 답이 수포자2과 같다면
    if i.1 == supoja2[i.0 % supoja2.count] {
        totalAns[1] += 1
    }
    // 현재 답이 수포자1과 같다면
    if i.1 == supoja3[i.0 % supoja3.count] {
        totalAns[2] += 1
    }
}
```

이렇게 나눠서 확인해야 함. 또한 %연산 특성을 이용한 것
<br/>

2. **_고득점자 한 명이 아닐 경우_**

그냥 간단함 배열의 최댓값인 값들의 인덱스를 +1해줘서 정답 배열에 넣어주면 됌
<br/>

```swift
let maxValue = totalAns.max() // 최고 득점

for i in 0..<3 {
    if totalAns[i] == totalAns.max() {
        answer.append(i + 1)
    }
}
```

이렇게 하면 간단히 해결할 수 있음
<br/>

## 최종 코드

스위프트

```swift
import Foundation

func solution(_ answers:[Int]) -> [Int] {
    var answer:[Int] = []
    let supoja1:[Int] = [1,2,3,4,5] // 길이 5
    let supoja2:[Int] = [2,1,2,3,2,4,2,5] // 길이 8
    let supoja3:[Int] = [3,3,1,1,2,2,4,4,5,5] // 길이 10

    var totalAns:[Int] = [0,0,0] // 합

    for i in answers.enumerated() {
        // 현재 답이 수포자1과 같다면
        if i.1 == supoja1[i.0 % supoja1.count] {
            totalAns[0] += 1
        }
        // 현재 답이 수포자2과 같다면
        if i.1 == supoja2[i.0 % supoja2.count] {
            totalAns[1] += 1
        }
        // 현재 답이 수포자1과 같다면
        if i.1 == supoja3[i.0 % supoja3.count] {
            totalAns[2] += 1
        }
    }

    let maxValue = totalAns.max()
    for i in 0..<3 {
        if totalAns[i] == totalAns.max() {
            answer.append(i + 1)
        }
    }
    return answer
}
```

C++

```cpp
#include <string>
#include <vector>

using namespace std;

int student1[5] = {1, 2, 3, 4, 5};
int student2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int student3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = {0, };
    int max_score = -1;

    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == student1[i % 5])
            score[0]++;

        if (answers[i] == student2[i % 8])
            score[1]++;

        if (answers[i] == student3[i % 10])
            score[2]++;
    }

    for (int i = 0; i < 3; ++i) {
        if (max_score < score[i])
            max_score = score[i];
    }

    for (int i = 0; i < 3; ++i) {
        if (max_score == score[i])
            answer.push_back(i + 1);
    }

    return answer;
}
```
