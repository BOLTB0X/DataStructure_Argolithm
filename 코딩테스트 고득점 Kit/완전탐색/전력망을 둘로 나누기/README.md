# 고득점 kit > 완전탐색 > 전력망을 둘로 나누기

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/86971?language=swift
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

문제를 이해해야함
<br/>

## 풀이

트리를 보고 별에별 생각을 했지만 간단하게 3가지 스탭으로 풀수 있는 문제
<br/>

1. 인전행렬 활용

   > n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있습니다.
   > <br/>

```swift
  // 인접행렬 이용
  var adjMat:[[Int]] = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)
  // (n+1) X (n+1) 행렬
```

<br/>

```swift
adjMat[1][2] = 1
adjMat[2][3] = 0
```

**_노드 1과 노드 2가 연결_**
<br/>

**_노드 2와 노드 3은 미연결_**
<br/>

이렇게 의미함 -> 각 송전탑의 연결 여부를 인접행렬으로 표시
<br/>

2. 완전탐색

   > 이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다.
   > <br/>
   > 이때, 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 합니다.
   > <br/>

   즉 인접행렬을 순회하면서 하나씩 연결을 끊고 **_끊은 인접행렬의 행과 열을 스타트로_** 완전탐색하면 됌
   <br/>
   여기서 최대한 비슷하게 만든다는 것은 스타트로 끊은 것들의 차이 중 최솟값을 달라는 뜻

```swift
 // for문으로 연결을 끊을 wire을 하나식 선정하며
// 완전탐색 진행
for i in 0..<wires.count {
    // 연결 해제
    adjMat[wires[i][0]][wires[i][1]] = 0
    adjMat[wires[i][1]][wires[i][0]] = 0

    // 끊은 노드로 BFS 탐색
    let ret1 = BFS(wires[i][0])
    let ret2 = BFS(wires[i][1])

    answer = min(answer, abs(ret1-ret2))

    // 다시 연결
    adjMat[wires[i][0]][wires[i][1]] = 1
    adjMat[wires[i][1]][wires[i][0]] = 1
}
```

3. DFS 쓸까 BFS인가

![img](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Ft1.daumcdn.net%2Fcfile%2Ftistory%2F2254723E588084F830)
<br/>

당연한 말이지만 DFS는 깊이우선, BFS는 너비우선임
<br/>

![img](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/5b8a0dcd-cba0-47ca-b5e3-d3bafc81f9d6/ex1.png)
<br/>

여기서 1로 DFS을 쓰면 재귀이던 스택을 쓰더 끊어진 노드를 제외하고 **_1-3-2-4-5-8_** 이런식으로 다 돌기는 할거임
<br/>

만약 문제에서 한 번에 쭈우우우욱 내리는 듯하게 탐색한 길이를 활용해야했으면 이 문제는 DFS 사용하지 못함
<br/>

하지만 이 문제는 노드 방문이므로 BFS/DFS를 써도 상관이 없음
<br/>

BFS

```swift
// MARK: adj식 BFS
func BFS(_ start: Int) -> Int{
    var res: Int = 0
    var visited:[Bool] = Array(repeating: false, count: n+1)
    var que:[Int] = [start]
    visited[start] = true

    while (que.count > 0) {
        var cur = que.removeFirst()
        res += 1
        // 현재 인접행렬의 갯수만큼 ==> 연결되어있는 수만큼
        // 현재 행의 열들의 값이 0이면 미연결 1이면 연결
        for i in 1...n {
            // 재방문
            if visited[i] {
                continue
            }

            // 미연결
            if adjMat[cur][i] == 0 {
                continue;
            }

            visited[i] = true
            que.append(i)
        }
    }

    return res
}
```

<br/>

DFS

```swift
// MARK: adj식 DFS
func DFS(_ visited:[Bool], _ cur:Int, _ depth:Int) -> Int {
    var depth = depth
    var visited = visited
    visited[cur] = true

    for i in 1...n {
        if visited[i] {
            continue;
        }

        if adjMat[cur][i] == 0 {
            continue
        }
        depth = DFS(visited, i, depth+1)
    }

    return depth
}
```

<br/>

이제 순차적으로 코드를 작성함면 됌
<br/>

## 최종 코드

```swift
import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    // 개수의 차이 값을 최대한 맞춘다
    // 즉 절대값 중 최솟값을 쓴다는 말
    var answer = Int.max;
    var visited:[Bool] = Array(repeating: false, count: n+1)
    // 인접행렬 이용
    var adjMat:[[Int]] = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)

    // MARK: adj식 BFS
    func BFS(_ start: Int) -> Int{
        var res: Int = 0
        var visited:[Bool] = Array(repeating: false, count: n+1)
        var que:[Int] = [start]
        visited[start] = true

        while (que.count > 0) {
            var cur = que.removeFirst()
            res += 1
            // 현재 인접행렬의 갯수만큼 ==> 연결되어있는 수만큼
            // 현재 행의 열들의 값이 0이면 미연결 1이면 연결
            for i in 1...n {
                // 재방문
                if visited[i] {
                    continue
                }

                // 미연결
                if adjMat[cur][i] == 0 {
                    continue;
                }

                visited[i] = true
                que.append(i) // 연결된 노드
            }

        }
        return res
    }


    // MARK: adj식 DFS
    func DFS(_ visited:[Bool], _ cur:Int, _ depth:Int) -> Int {
        var depth = depth
        var visited = visited
        visited[cur] = true

        for i in 1...n {
            if visited[i] {
                continue;
            }

            if adjMat[cur][i] == 0 {
                continue
            }

            depth = DFS(visited, i, depth+1)
        }

        return depth
    }


    // 인접행렬 연결
    for i in 0..<wires.count {
        // 양방향이므로
        adjMat[wires[i][0]][wires[i][1]] = 1
        adjMat[wires[i][1]][wires[i][0]] = 1
    }

    //print(adjMat)

    // for문으로 연결을 끊을 wire을 하나식 선정하며
    // 완전탐색 진행
    for i in 0..<wires.count {
        // 연결 해제
        adjMat[wires[i][0]][wires[i][1]] = 0
        adjMat[wires[i][1]][wires[i][0]] = 0

//        // 끊은 노드로 BFS 탐색
//        let ret1 = BFS(wires[i][0])
//        let ret2 = BFS(wires[i][1])
        var visited:[Bool] = Array(repeating: false, count: n+1)
        let ret1 = DFS(visited, wires[i][0],0)
        let ret2 = DFS(visited, wires[i][1],0)

        answer = min(answer, abs(ret1-ret2))

        // 다시 연결
        adjMat[wires[i][0]][wires[i][1]] = 1
        adjMat[wires[i][1]][wires[i][0]] = 1
    }

    return answer
}

```
