# 고득점 kit > 힙(Heap) > 이중우선순위큐

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42628
<br/>

문제설명, 제한사항 생략
<br/>

## Intro

힙 쓸수 있니?

<br/>

## 풀이

말 그대로 힙을 쓸수 있냐고 묻는 문제
<br/>

> I 숫자: 큐에 주어진 숫자를 삽입합니다.
> <br/>
> D 1: 큐에서 최댓값을 삭제합니다.
> <br/>
> D -1: 큐에서 최솟값을 삭제합니다.
> <br/>

이를 구현하면 끝
<br/>

```swift
for op in operations {
    let splitedOP = op.split(separator: " ")

    if splitedOP[0] == "I" {
        pq.append(Int(splitedOP[1])!)
        pq.sort(by: >)
    } else if splitedOP[0] == "D" {
        if pq.count > 0 && splitedOP[1] == "1" {
            pq.removeFirst()
        } else if pq.count > 0 && splitedOP[1] == "-1" {
            pq.removeLast()
        }
    }
}
```

<br/>

## 제출 코드

```swift
import Foundation

func solution(_ operations:[String]) -> [Int] {
    var answer:[Int] = []
    var pq:[Int] = []

    for op in operations {
        let splitedOP = op.split(separator: " ")

        if splitedOP[0] == "I" {
            pq.append(Int(splitedOP[1])!)
            pq.sort(by: >)
        } else if splitedOP[0] == "D" {
            if pq.count > 0 && splitedOP[1] == "1" {
                pq.removeFirst()
            } else if pq.count > 0 && splitedOP[1] == "-1" {
                pq.removeLast()
            }
        }
    }

    if pq.count > 0 {
        answer = [pq.first!, pq.last!]
    } else {
        answer = [0, 0]
    }
    return answer
}
```
