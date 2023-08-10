# 고득점 kit > 그래프 > 가장 먼 노드

## 문제

Level 3
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/49189
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

다익스트라
<br/>

## 풀이

말 그대로 1번 노드로 부터 가장 많이 떨어진 노드의 개수를 구하면 됌
<br/>

이를 BFS와 다익스트라로 해결 가능
<br/>

#### BFS

기존 BFS 방식과 같이 인접리스트를 순회할 준비를 하고
<br/>

```swift
var que:[Int] = [start]
var depth:Int = 0
dist1[start] = 1
```

<br/>

각 탐색을 할때 가장 긴 거리를 큐에 넣을 때마다 확인하면 됌
<br/>

```swift
// 큐가 비어질때까지
while que.count > 0 {
    var cur = que.removeFirst()

    for i in adjList[cur] {
        // 재방문
        if dist1[i] != 0 {
            continue
        }

        dist1[i] = dist1[cur]+1 // 거리 자취를 남김
        maxDepth = max(maxDepth, dist1[i]) // 최댓값
        que.append(i)
    }
}
```

<br/>

#### 다익스트라(dijikstra)

다익스트라로 해결을 하려면 각 거리를 담을 리스트에 최대치를 넣어줘여 함
<br/>

```python
dist = [float('inf')] * (n+1)
```

<br/>

또한 BFS와 다르게 우선 순위 큐를 주로 이용
<br/>

```python
pq = []
heapq.heappush(pq, [0, 1])
```

<br/>

각 노드를 최단 경로로 넘어가니 BFS에선 재방문으로 하면 여긴 크거나 같으면 그 노드를 지나갈 수 없도록 함
<br/>

```python
while pq:
    d, cur = heapq.heappop(pq)

    if dist[cur] < d:
        continue

    for next in adj[cur]:
        if d + 1 >= dist[next]:
            continue
        dist[next] = d+1
        heapq.heappush(pq, [d+1, next])
```

<br/>

## 최종 코드

```python
import heapq


def solution(n, edge):
    answer = 0

    adj = [[] for _ in range(n+1)]
    dist = [float('inf')] * (n+1)

    for e in edge:
        adj[e[0]].append(e[1])
        adj[e[1]].append(e[0])

    # 다익스트라
    pq = []
    heapq.heappush(pq, [0, 1])
    dist[1] = 0

    while pq:
        d, cur = heapq.heappop(pq)

        if dist[cur] < d:
            continue

        for next in adj[cur]:
            if d + 1 >= dist[next]:
                continue
            dist[next] = d+1
            heapq.heappush(pq, [d+1, next])

    answer = dist[1:].count(max(dist[1:]))
    return answer
```

<br/>

```swift
import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var answer:Int = 0
    var adjList = Array(repeating: [Int](), count: n+1) // 인접리스트
    var dist1 = Array(repeating: 0, count:n+1) // 거리 배열 BFS 용
    var dist2 = Array(repeating: Int.max, count:n+1) // dijikstra용
    var maxDepth:Int = Int.min // 최댓값을 위해

    // 너비우선탐색
    func BFS(_ start:Int) {
        var que:[Int] = [start]
        var depth:Int = 0
        dist1[start] = 1

        // 큐가 비어질때까지
        while que.count > 0 {
            var cur = que.removeFirst()

            for i in adjList[cur] {
                // 재방문
                if dist1[i] != 0 {
                    continue
                }

                dist1[i] = dist1[cur]+1 // 거리 자취를 남김
                maxDepth = max(maxDepth, dist1[i]) // 최댓값
                que.append(i)
            }
        }
        return
    }
```
