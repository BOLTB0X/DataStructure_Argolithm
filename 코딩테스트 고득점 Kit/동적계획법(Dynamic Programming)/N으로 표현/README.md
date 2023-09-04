# 고득점 kit > 동적계획법(Dynamic Programming) > N으로 표현

## 문제

Level 3
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42895
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

DFS
<br/>

## 풀이

> 아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.
> <br/>
> 12 = 5 + 5 + (5 / 5) + (5 / 5) --> 6
> <br/>
> 12 = 55 / 5 + 5 / 5 --> 5
> <br/>
> 12 = (55 + 5) / 5 --> 4
> <br/>

```swift
var numbers:[Int: Int] = [:]

numbers[1] = 2
numbers[N] = 1
numbers[11] = 3
numbers[11*N] = 2
numbers[111] = 4
numbers[111*N] = 3
numbers[1111] = 5
numbers[1111*N] = 4
numbers[11111] = 6
numbers[11111*N] = 5
```

<br/>

```swift
func DFS(_ total: Int, _ target: Int, _ depth: Int) {
    if depth >= answer {
        return
    }

    if total == target {
        answer = depth
        return
    }

    for (key, value) in numbers {
        DFS(total+key, target, depth+value)
        DFS(total-key, target, depth+value)
        DFS(total/key, target, depth+value)
        DFS(total*key, target, depth+value)
    }
    return
}
```

<br/>

## 최종 코드

```swift
import Foundation

func solution(_ N:Int, _ number:Int) -> Int {
    var answer:Int = 9
    var numbers:[Int: Int] = [:]

    func DFS(_ total: Int, _ target: Int, _ depth: Int) {
        if depth >= answer {
            return
        }

        if total == target {
            answer = depth
            return
        }

        for (key, value) in numbers {
            DFS(total+key, target, depth+value)
            DFS(total-key, target, depth+value)
            DFS(total/key, target, depth+value)
            DFS(total*key, target, depth+value)
        }
        return
    }

    numbers[1] = 2
    numbers[N] = 1
    numbers[11] = 3
    numbers[11*N] = 2
    numbers[111] = 4
    numbers[111*N] = 3
    numbers[1111] = 5
    numbers[1111*N] = 4
    numbers[11111] = 6
    numbers[11111*N] = 5

    DFS(0, number, 0)
    answer = answer == 9 ? -1 : answer
    return answer
}
```
