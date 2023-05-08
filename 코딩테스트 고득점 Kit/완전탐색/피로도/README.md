# 고득점 kit > 완전탐색 > 피로도

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/87946
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

순열
<br/>

## 풀이

문제에서 핵심은 딱 이 문구임
<br/>

> 각 던전마다 탐험을 시작하기 위해 필요한 "최소 필요 피로도"와 던전 탐험을 마쳤을 때 소모되는 "소모 피로도"가 있습니다.
> <br/>
> 예를 들어 "최소 필요 피로도"가 80, "소모 피로도"가 20인 던전을 탐험하기 위해서는 유저의 현재 남은 피로도는 80 이상 이어야 하며, 던전을 탐험한 후에는 피로도 20이 소모됩니다.
> <br/>

즉 현재 배열의 첫번째를 맞닥 드린다면 현재 체력이 최소 필요 피로도보다 커야하고 이동 후 소모 피로도 만큼 체력이 깎임
<br/>

> 유저의 현재 피로도 k와 각 던전별 "최소 필요 피로도", "소모 피로도"가 담긴 2차원 배열 dungeons 가 매개변수로 주어질 때, 유저가 탐험할수 있는 최대 던전 수
> <br/>

즉 "최소 필요도"를 확인하고 체력을 깎여가며 진행할 때 저 배열을 어떻게 순회해야지 많이 진행할 수 있는지를 묻는 문제
<br/>

**_여기서 DFS로 순열하듯히 풀면 해결이 가능_**

1. 방문리스트 생성

```swift
// 방문리스트
var visited = Array(repeating: false, count: dungeons.count);
```

저 배열을 탐색하며 탐색한 순서를 남기기 위해 방문리스트가 필요
<br/>

2. DFS

   1. DFS 메소드 내 for문으로 dungeons의 길이 만큼 반복시킴
      <br/>
   2. for문 내 재방문인 경우와 현재 체력으로 진행을 못하는 경우를 패스 시킴
      <br/>
   3. 현재 진행이 가능하면 소모 필요도를 깎고 최대 길이인지 확인
      <br/>

```swift
// 던전 확인
for i in 0..<dungeons.count {
    // 재방문인 경우
    if visited[i] == true {
        continue
    }

    // 현재 체력으로 최소필요피로도를 소화할수 없는 경우
    if cur < dungeons[i][0] {
        continue
    }

    var next = cur // 파라미터는 let이므로
    visited[i] = true // 방문 체크
    answer = max(answer, level+1) // 정답 체크
    DFS(next-dungeons[i][1], level+1) // DFS 호출
    visited[i] = false // 순열처럼 순서를 바꿔가며 진행하니
}
```

3. 참고

탐색의 길이를 체크하는 방법은 2가지임
<br/>

- if문 용 (DFS 내 for문 순회 이전에 선언)
  <br/>

```swift
if depth > answer {
    answer = depth
}
```

<br/>

- 다음 DFS 호출 전 체크
  <br/>

```swift
answer = max(answer, level+1) // 정답 체크
DFS(next-dungeons[i][1], level+1) // DFS 호출
```

## 최종 코드

스위프트 1차
<br/>

```swift
import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer: Int = 0
    // 방문리스트
    var visited: [Bool] = Array(repeating: false, count: 9)

    func DFS(cur: Int, board: [[Int]], depth: Int) {
        // 다 돌았다면
        if depth > answer {
            answer = depth
        }

        for i in 0..<board.count {
            // 재방문
            if visited[i] {
                continue;
            }

            // 현재가 최소필요도보다 크다면 재귀 호출
            if cur >= board[i][0] {
                visited[i] = true
                DFS(cur: cur-board[i][1], board: board, depth: depth+1)
                visited[i] = false
            }
        }
        return
    }

    // dfs로 순열 시작
    DFS(cur: k, board: dungeons, depth: 0)
    return answer
}

```

스위프트 2차
<br/>

```swift
import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer = 0;
    // 방문리스트
    var visited = Array(repeating: false, count: dungeons.count);

    // MARK: 깊이우선탐색
    func DFS(_ cur:Int, _ level:Int) {
        // 던전 확인
        for i in 0..<dungeons.count {
            // 재방문인 경우
            if visited[i] == true {
                continue
            }

            // 현재 체력으로 최소필요피로도를 소화할수 없는 경우
            if cur < dungeons[i][0] {
                continue
            }

            var next = cur // 파라미터는 let이므로
            visited[i] = true // 방문 체크
            answer = max(answer, level+1) // 정답 체크
            DFS(next-dungeons[i][1], level+1) // DFS 호출
            visited[i] = false // 순열처럼 순서를 바꿔가며 진행하니
        }
    }

    DFS(k,0); // 0부터 시작

    return answer;
}
```
