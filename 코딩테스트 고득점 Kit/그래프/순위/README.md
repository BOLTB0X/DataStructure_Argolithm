# 고득점 kit > 그래프 > 순위

## 문제

Level 3
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/49191
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

플로이드
<br/>

## 풀이

플로이드 워셜 알고리즘을 이용해야함
<br/>

문제에서 알수 있듯히 노드수가 적음 또한 1번 선수가 2번 선수를 이기고 2번 선수가 3번 선수를 이긴다 하면 **(1,2), (2,3) ==> (1,3)** 을 표현해야하는 문제임
<br/>

이를 플로이드 워셜로 나타내면 되는 것
<br/>

```python
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            if adj[a][k] == 1 and adj[k][b] == 1:
                adj[a][b] = 1
            elif adj[a][k] == -1 and adj[k][b] == -1:
                adj[a][b] = -1
```

<br/>

**a가 k를 이기고 k가 b를 이기면 ==> (a,b) = 1 처리**
<br/>

**a가 k에게 지고 k가 b에게 지면 ==> (a,b) = -1 처리**
<br/>

## 최종 제출 코드

```python
def solution(n, results):
    answer = 0
    adj = [[0] * (n+1) for _ in range(n+1)]

    for res in results:
        adj[res[0]][res[1]] = 1
        adj[res[1]][res[0]] = -1

    for k in range(1, n+1):
        for a in range(1, n+1):
            for b in range(1, n+1):
                if adj[a][k] == 1 and adj[k][b] == 1:
                    adj[a][b] = 1
                elif adj[a][k] == -1 and adj[k][b] == -1:
                    adj[a][b] = -1

    for i in range(1, n+1):
        if adj[i][1:].count(0) == 1:
            answer += 1

    return answer

```

<br/>

```swift
import Foundation

func solution(_ n:Int, _ results:[[Int]]) -> Int {
    var answer:Int = 0
    var adj:[[Int]] = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)

    for res in results {
        adj[res[0]][res[1]] = 1
        adj[res[1]][res[0]] = -1
    }

    for k in 1...n {
        for a in 1...n {
            for b in 1...n {
                if adj[a][k] == 1 && adj[k][b] == 1 {
                    adj[a][b] = 1
                } else if adj[a][k] == -1 && adj[k][b] == -1 {
                    adj[a][b] = -1
                }
            }
        }
    }

    for i in 1...n {
        var cnt: Int = 0
        for j in 1...n {
            if adj[i][j] == 0 {
                cnt += 1
            }
        }
        if cnt == 1 {
            answer += 1
        }
    }

    return answer
}
```
