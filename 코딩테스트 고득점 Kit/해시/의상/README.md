# 고득점 kit > 해시 > 의상

## 문제

Level 2
<br/>

[문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/42578?language)
<br/>

문제설명, 제한사항 생략
<br/>

## Intro

경우의 수
<br/>

## 풀이

중복 조합을 생각하면 됌
<br/>

중복 조합 공식에 약간의 생각으로 비틀어야 함
<br/>

> 예를 들어 5개 과일 중 3개를 선택해야하면
> <br/>
> 이 경우의 수는 5 X 5 X 5 임
> <br/>

그런데 문제에선 최소한 1개의 옷은 입고 같은 카테고리 옷은 중복해서 안 입는 다 함
<br/>

그럼 이 옷을 안입는 경우도 생각해야 한다는 것
<br/>

**즉 A+1 X B+1 X C+1** 이 공식에 마지막 아무것도 않은 수인 1을 빼주면 된다는 것
<br/>

문제에 대입해 표현하면, 딕셔너리로 중복 되는 종류를 체크 후 의상의 개수가 A, B, C 라면 -> 전체 조합의 개수는 (A+1) _ (B+1) _ (C+1) - 1

코딩에서 카테고리를 분류해야하므로 **딕셔너리** 이용
<br/>

```python
dic = {clothe[1] : [] for clothe in clothes}

for clothe in clothes:
    dic[clothe[1]].append(clothe[0])
```

<br/>

```swift
for clothe in clothes {
    if let _ = dic[clothe[1]] {
        dic[clothe[1]]? += 1
    } else {
        dic[clothe[1]] = 1
    }
}
```

<br/>

## 제출 코드

```python
# 파이썬
def solution(clothes):
    answer = 1

    dic = {clothe[1] : [] for clothe in clothes}

    for clothe in clothes:
        dic[clothe[1]].append(clothe[0])

    #print(dic)

    for value in dic.values():
        answer *= (len(value)+1)

    return answer-1
```

<br/>

```swift
// 스위프트
import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var answer: Int = 1
    var dic:[String: Int] = [:]

    for clothe in clothes {
        if let _ = dic[clothe[1]] {
            dic[clothe[1]]? += 1
        } else {
            dic[clothe[1]] = 1
        }
    }

    for (ket, value) in dic {
        answer *= (value+1)
    }


    return answer-1
}
```

<br/>
