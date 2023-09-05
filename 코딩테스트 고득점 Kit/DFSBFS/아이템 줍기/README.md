# 고득점 kit > DFS/BFS > 아이템 줍기

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/87694
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

테두리를 어떻게 체크할까
<br/>

## 풀이

![이미지](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/38b0739b-8dd8-40d8-ac44-c71678d28d07/rect_2.png)
<br/>

이런 식으로 겹치는 테두리들만 BFS를 진행해야하는 문제
<br/>

맨 처음에는 감이 안잡혀 다른 사람들의 코드를 참조했슴
<br/>

```python
x1 < i and x2 > i and y1 < j and y2 > j
```

이처럼 사이 값에는 이동하지 못하게 처리
<br/>

```swift
for rect in rectangle {
    let newRect = rect.map { $0*2 }

    for i in newRect[0]...newRect[2] {
        for j in newRect[1]...newRect[3] {
            if newRect[0] < i && newRect[2] > i && newRect[1] < j && newRect[3] > j {
                board[i][j] = 0
            } else if board[i][j] != 0 {
                board[i][j] = 1
            }
        }
    }
}
```

<br/>

```python
for rect in rectangle:
    x1, y1, x2, y2 = rect[0]*2, rect[1]*2, rect[2]*2, rect[3]*2

    for i in range(x1, x2+1):
        for j in range(y1, y2+1):
            # 테두리 안
            if x1 < i and x2 > i and y1 < j and y2 > j:
                board[i][j] = 0
            elif board[i][j] != 0:
                board[i][j] = 1
```

<br/>

그런데 여기서 두 배를 해주는 것을 알 수 있음 이는 테두리로만 이동해야할 경우 안되는 경우가 있기 때문

0 1 1 0 -> 0 x x 0 -> 0 1 x 0
<br/>

0 1 1 0 -> 0 x x 0 -> 0 1 x 0
<br/>

0 0 1 0 -> 0 0 x 0 -> 0 0 x 0
<br/>

0 1 1 0 -> 0 x x 0 -> 0 x x 0
<br/>

이런 경우가 있을 수 있으므로 격자판과 위치를 2배 해주고 길이를 2로 나눠줘야 함
<br/>

```swift
if cur[0] == tx && cur[1] == ty {
    ret = dist[tx][ty] / 2
    break
}
```

<br/>

```python
if cx == itemX * 2 and cy == itemY * 2:
    return dist[cx][cy] // 2
```

## 최종코드

```swift
import Foundation

func solution(_ rectangle: [[Int]], _ characterX: Int, _ characterY: Int, _ itemX: Int, _ itemY: Int) -> Int {
    var answer:Int = 0
    var board: [[Int]] = Array(repeating: Array(repeating: -1, count: 102), count: 102)

    func BFS(_ sx: Int, _ sy: Int, _ tx: Int, _ ty: Int) -> Int {
        var ret:Int = 0
        var dist = Array(repeating: Array(repeating: 0, count: 102), count: 102)
        var que:[[Int]] = []
        var qIdx: Int = 0

        let dir:[[Int]] = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        que.append([sx, sy])
        dist[sx][sy] = 1

        while qIdx < que.count {
            let cur = que[qIdx]
            qIdx += 1

            if cur[0] == tx && cur[1] == ty {
                ret = dist[tx][ty] / 2
                break
            }

            for d in dir {
                let nx = cur[0] + d[0]
                let ny = cur[1] + d[1]

                if nx < 0 || ny < 0 || nx >= 102 || ny >= 102 {
                    continue
                }

                if dist[nx][ny] > 0 || board[nx][ny] != 1 {
                    continue
                }

                que.append([nx, ny])
                dist[nx][ny] = dist[cur[0]][cur[1]] + 1
            }
        }

        return ret
    }

    for rect in rectangle {
        let newRect = rect.map { $0*2 }

        for i in newRect[0]...newRect[2] {
            for j in newRect[1]...newRect[3] {
                if newRect[0] < i && newRect[2] > i && newRect[1] < j && newRect[3] > j {
                    board[i][j] = 0
                } else if board[i][j] != 0 {
                    board[i][j] = 1
                }
            }
        }
    }

    answer = BFS(characterX*2, characterY*2, itemX*2, itemY*2)

    return answer
}

```

<br/>

```python
from collections import deque


def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    board = [[-1] * 102 for _ in range(102)]

    def BFS():
        que = deque()
        dist = [[0] * 102 for _ in range(102)]
        dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        que.append((characterX*2, characterY*2))
        dist[characterX*2][characterY*2] = 1

        while que:
            cx, cy = que.popleft()

            if cx == itemX * 2 and cy == itemY * 2:
                return dist[cx][cy] // 2

            for d in dir:
                nx = cx+d[0]
                ny = cy+d[1]

                if nx < 0 or ny < 0 or nx >= 102 or ny >= 102:
                    continue

                if dist[nx][ny] or board[nx][ny] != 1:
                    continue

                que.append((nx, ny))
                dist[nx][ny] = dist[cx][cy] + 1

        return

    for rect in rectangle:
        x1, y1, x2, y2 = rect[0]*2, rect[1]*2, rect[2]*2, rect[3]*2

        for i in range(x1, x2+1):
            for j in range(y1, y2+1):
                # 테두리 안
                if x1 < i and x2 > i and y1 < j and y2 > j:
                    board[i][j] = 0
                elif board[i][j] != 0:
                    board[i][j] = 1

    answer = BFS()

    return answer

```

<br/>
