# 고득점 kit > DFS/BFS > 단어 변환

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/43163
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

백 트래킹
<br/>

## 풀이

> 1. 한 번에 한 개의 알파벳만 바꿀 수 있습니다.
>    <br/>
> 2. words에 있는 단어로만 변환할 수 있습니다.
>    <br/>

즉 단어중 문자를 하나 씩 바꿔서 최소 몇번 만에 목표 타겟이 되냐인 문제
<br/>

여기서 **백트래킹**을 떠올려야함
<br/>

변환을 해서 가능하냐를 넘어 최소 횟수가 뭐냐고 문제에서 물음
<br/>

그럼 진행과정을 막 다르게 할 필요가 있다는 것
<br/>

```swift
visited[i] = true
DFS(words[i], depth+1)
visited[i] = false
```

<br/>

또한 진행 과정에서 하나만 다른 경우에만 진행하도록 조건을 걸어주면 됌
<br/>

```swift
// 스위프트
func check(_ cur: [String], _ next: [String]) -> Bool {
    var cnt:Int = 0

    for i in 0..<cur.count {
        if cur[i] != next[i] {
            cnt += 1
        }
    }

    return cnt == 1 ? true : false
}
```

<br/>

```python
# 파이썬
def is_change(word1, word2):
    w = 0
    for i in range(len(word1)):
        if word1[i] != word2[i]:
            w += 1

    return True if w == 1 else False
```

<br/>

## 제출 코드

```swift
// 스위프트
import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var answer:Int = Int.max
    var visited:[Bool] = Array(repeating: false, count: words.count)

    func check(_ cur: [String], _ next: [String]) -> Bool {
        var cnt:Int = 0

        for i in 0..<cur.count {
            if cur[i] != next[i] {
                cnt += 1
            }
        }

        return cnt == 1 ? true : false
    }

    func DFS(_ cur: String, _ depth: Int) {
        if cur == target {
            answer = min(depth, answer)
            return
        }

        for i in 0..<words.count {
            if visited[i] {
                continue
            }

            if !check(cur.map{String($0)}, words[i].map{String($0)}) {
                continue
            }

            visited[i] = true
            DFS(words[i], depth+1)
            visited[i] = false
        }
        return
    }

    if words.contains(target) {
        DFS(begin, 0)
    } else {
        answer = 0
    }

    return answer
}
```

<br/>

```python
# 파이썬
import sys
sys.setrecursionlimit(51)

def solution(begin, target, words):
    answer = 51
    visited = [False] * len(words)

    def is_change(word1, word2):
        w = 0
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                w += 1

        return True if w == 1 else False

    def DFS(cur, target, words, visited, depth):
        nonlocal answer

        # 도달 했다면
        if cur == target:
            answer = min(answer, depth) # 최솟값 반환
            return

        for i in range(len(words)):
            # 변환 가능하고 미방문
            if is_change(cur, words[i]) and not visited[i]:
                visited[i] = True
                DFS(words[i], target, words, visited, depth + 1)
                visited[i] = False
        return

    if target in words:
        # dfs
        DFS(begin, target, words, visited, 0)
    else:
        answer = 0
    return answer
```

<br/>
