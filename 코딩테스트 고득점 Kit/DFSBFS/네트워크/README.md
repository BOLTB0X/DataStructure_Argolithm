# 고득점 kit > DFS/BFS > 네트워크

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/43165
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

**_전형적인 DFS 탐색 문제_**
<br/>

## 풀이

간단함 몇개가 연결되어 있다는 것은 시작 노드를 1번 부터 n번 노드로 호출해서 총 몇번 호출 되었지를 확인 하면 됌

```swift
// 스위프트
for i in 0..<n {
    if visited[i] == false { // 미방문 발견할때마다 카운팅
        DFS(computers, cur: i)
        answer += 1
    }
}
```

<br/>

```python
# 파이썬
for i in range(n):
    if not visited[i]:
        DFS(i)
        answer += 1
```

<br/>

DFS 함수는 그냥 말그대로 탐색으로 구현하면 끝
<br/>

```swift
// 스위프트
func DFS(_ computers:[[Int]], cur: Int) {
    visited[cur] = true // 방문

    for i in 0..<n {
        // 연결되어있고 미방문이면
        if visited[i] == false && computers[cur][i] == 1 {
            // dfs
            DFS(computers, cur: i)
        }
    }
    return
}
```

<br/>

```python
# 파이썬
def DFS(cur):
    nonlocal visited
    visited[cur] = True

    for i in range(n):
        if not visited[i] and computers[cur][i]:
        DFS(i)
```

<br/>

## 제출 코드

```swift
// 스위프트
import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    // 방문리스트
    var visited: [Bool] = Array(repeating: false, count: n)
    var answer: Int = 0 // 정답

    // 깊이우선 탐색
    func DFS(_ computers:[[Int]], cur: Int) {
        visited[cur] = true // 방문

        for i in 0..<n {
            // 연결되어있고 미방문이면
            if visited[i] == false && computers[cur][i] == 1 {
                // dfs
                DFS(computers, cur: i)
            }
        }
        return
    }

    // 하나씩 확인
    for i in 0..<n {
        if visited[i] == false { // 미방문 발견할때마다 카운팅
            DFS(computers, cur: i)
            answer += 1
        }
    }
    return answer
}
```

<br/>

```python
# 파이썬
def solution(n, computers):
    answer = 0
    visited = [False for _ in range(n)]

    def DFS(cur):
        nonlocal visited
        visited[cur] = True

        for i in range(n):
            if not visited[i] and computers[cur][i]:
                DFS(i)

    for i in range(n):
        if not visited[i]:
            DFS(i)
            answer += 1

    return answer
```
