# 코딩테스트 연습 > 정렬 > H-Index

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42747
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

의외로 생각을 길게했던 문제. 문제를 그냥 읽기만 해서는 안되는 것을 느낌

## 풀이

문제의 예시를 직접 하나씩 짚어보면서 확인해 보면 논문배열 [3, 0, 6, 1, 5]의 의미는 다음과 같음
<br/>

인덱스 0: 인용 3
<br/>
인덱스 1: 인용 0
<br/>
인덱스 2: 인용 6
<br/>
인덱스 3: 인용 1
<br/>
인덱스 4: 인용 5
<br/>

각 논문들이 인용된 횟수를 말해줌. 이렇게 문제를 다시 읽어보면
<br/>

> 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index
> <br/>

읽다보면 h편 이상, h편 이하로 나눠 보고 이중 최댓값을 구해야함.
h번 이상과 나머지가 이하란 조건을 봐서 h를 2로 잡아보면 h 이상은 (3,6,5), h 이상이 2 이상으로 X
h를 3로 잡아보면 h 이상은 (3,6,5), h 이하는 3이하인 (0, 1)임
<br/>

이걸 보면 원소들을 내림 차순으로도 가능하다는 생각이 들거임 (6, 5, 3, 1, 0), hidx = 0으로 같이 표현해보면
<br/>

6 > hidx:0 => 0에서 1로 증가
<br/>

5 > hidx:1 => 1에서 2로 증가
<br/>

3 > hidx:2 => 2에서 3으로 증가
<br/>

1 < hidx:3 ===> **_여기가 hidx의 최댓값_**
<br/>

이하는 다 hidx에 해당하므로 첫 조건에 맞닥드리는 부분이 최댓값임
<br/>

처음 문제를 봤을 때 인덱스에 초점을 두지 않고 횟수만 생각하다보니 생각이 길어진 문제 -> **문제의 관건은 기점을 나눠주는 인덱스를 찾아주는 것**
<br/>

```swift
// 내림차순 정렬
var citations = citations.sorted(by: >)
```

먼저 내림차순으로 정렬해줌
<br/>

```swift
// hidx를 판단하기 위해서 제일 먼저 배열의 값을 보고
// 카운트를 하다 같아지거나 초과할 경우에 멈춰야함
for i in 0..<citations.count {
    if citations[i] > answer {
        answer += 1
    } else {
        break;
    }
}
```

만약 저 if문 조건을 >=으로 하고 싶으면?

```swift
for i in 0..<citations.count {
    if citations[i] >= answer {
        answer = i + 1
    } else {
        break
    }
}
```

## 최종 코드

```swift
import Foundation

func solution(_ citations:[Int]) -> Int {
    var answer: Int = 0 // 정답
    // 오름차순 정렬
    var citations = citations.sorted(by: >)

    // hidx를 판단하기 위해서 제일 먼저 배열의 값을 보고
    // 카운트를 하다 같아지거나 초과할 경우에 멈춰야함
    for i in 0..<citations.count {
        if citations[i] > answer {
            answer += 1
        } else {
            break;
        }
    }
    return answer
}
```
