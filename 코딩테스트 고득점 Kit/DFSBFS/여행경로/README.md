# 고득점 kit > DFS/BFS > 단어 변환

## 문제

Level 3
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/43164
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

백 트래킹+DFS 과정 조금 틀기
<br/>

## 풀이

```swift
var tickets = tickets.sorted { $0[1] < $1[1] }
```

<br/>

백트래킹으로 해결해야함
<br/>

현재에서 -> 이동 가능한 목적지를 배열을 순회하면서 만나면 백트래킹 해주면 됨
<br/>

즉 dfs로 순열을 작성하듯이 풀이하면 해결할 수 있음
<br/>

```swift
// 하나씩 확인
for i in 0..<tickets.count {
    let start = tickets[i][0] // 출발지
    let next = tickets[i][1] // 다음 행성지

    // 미방문이고 현재 진행할 수 있다면
    if !visited[i] && cur == start {
        visited[i] = true
        path.append(next) // 추가

        DFS(next, path) // 다음 진행을 위해 호출

        // 다른 케이스를 위해
        path.removeLast()
        visited[i] = false
    }
}
```

<br/>

```python
for i in range(len(tickets)):
    start = tickets[i][0]
    end = tickets[i][1]

    if not visited[i] and cur == start:
        visited[i] = True
        path.append(end)

        DFS(visited, end, path)

        path.pop()
        visited[i] = False
```

<br/>

또한 재귀문의 탈출 조건을 달아주면 진짜 끝
<br/>

답이 나온 경우
<br/>

```swift
// 답이 나온 경우
if answer.count != 0 {
    return
}
```

```python
if answer:
    return
```

<br/>

답을 발견한 경우

```swift
// 현재 위치에서 더 돌아다닐 곳이 없다면
if  answer.count == 0 && path.count == tickets.count + 1 {
    // 첫 번째로 도착한 path가 정답
    answer = path
    return // 탈출
}
```

```python
if not answer and len(path) == len(tickets)+1:
    answer.extend(path)
    return
```

<br/>

## 제출 코드

```swift
// 스위프트
import Foundation

func solution(_ tickets:[[String]]) -> [String] {
    var answer:[String] = [] // 정답
    var visited = Array(repeating: false, count: tickets.count)
    var tickets = tickets.sorted { $0[1] < $1[1] }

    func DFS(_ cur:String, _ path: [String]) {
        if answer.count != 0 {
            return
        }

        if  answer.count == 0 && path.count == tickets.count + 1 {
            answer = path
            return
        }

        var path = path

        for i in 0..<tickets.count {
            let start = tickets[i][0]
            let next = tickets[i][1]

            if !visited[i] && cur == start {
                visited[i] = true
                path.append(next)

                DFS(next, path)

                path.removeLast()
                visited[i] = false
            }
        }
    }

    DFS("ICN", ["ICN"])

    return answer
}
```

<br/>

```python
# 파이썬
def solution(tickets):
    answer = []
    visited = [False] * len(tickets)
    tickets.sort()

    def DFS(visited, cur, path):
        nonlocal answer
        if answer:
            return

        if not answer and len(path) == len(tickets)+1:
            answer.extend(path)
            return

        for i in range(len(tickets)):
            start = tickets[i][0]
            end = tickets[i][1]

            if not visited[i] and cur == start:
                visited[i] = True
                path.append(end)

                DFS(visited, end, path)

                path.pop()
                visited[i] = False
        return

    DFS(visited, "ICN", ["ICN"])
    return answer
```

<br/>
