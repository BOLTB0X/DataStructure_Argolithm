# 고득점 kit > DFS/BFS > 게임 맵 최단거리

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/1844?language=cpp
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

**_DFS인가 BFS인가 무엇을 쓸지 고민하게 해주는 탐색 문제_**
<br/>

## 풀이

> 각 팀은 상대 팀 진영에 최대한 빨리 도착하는 것이 유리합니다.
> <br/>
> ....
> <br/>
> 5 x 5 크기의 맵에, 당신의 캐릭터가 (행: 1, 열: 1) 위치에 있고, 상대 팀 진영은 (행: 5, 열: 5) 위치
> <br/>

문제에서 해결해달라는 것은 정방행렬에서 (0,0)에서 (n-1, n-1)까지 최단 거리 몇이냐 묻는 것
<br/>

1이 갈 수 있는 곳이고 0은 벽임
<br/>

최단 거리를 구하기 위해선 **_"BFS"_** 이용해야함
<br/>

만약 DFS를 사용하게 되면 안되는 예를 들어보겠음
<br/>
격자판 5x5이 인 이런 예시가 있다고 치자
<br/>

1 | 0 | 1 | 1 | 1
<br/>
1 | 0 | 1 | 0 | 1
<br/>
1 | 0 | 1 | 1 | 1
<br/>
1 | 1 | 1 | 0 | 1
<br/>
0 | 0 | 0 | 0 | 1
<br/>

여기서 문제 예시에 최단거리를 2로 표현해보면
<br/>

2 | 0 | 1 | 1 | 1
<br/>
2 | 0 | 1 | 0 | 1
<br/>
2 | 0 | 2 | 2 | 2
<br/>
2 | 2 | 2 | 0 | 2
<br/>
0 | 0 | 0 | 0 | 2
<br/>

이런 칸을 밟으면서 11칸을 나오게 되는 데, 여기서 주목해야 할 구간(# 적어놓은 곳)
<br/>
2 | 0 | 1 | 0 | 1
<br/>
2 | 0 | # | 2 | 2
<br/>
2 | 2 | 2 | 0 | 2(목적지)
<br/>

이 부분임. 만약 여기서 DFS 탐색을 하면 동 서 남 북 중 북쪽을 우선으로 탐색하게 됌. 즉
<br>

2 | 0 | 2 | 2 | 2
<br/>
2 | 0 | 2 | 0 | 2
<br/>
2 | 0 | 2 | 1 | 2
<br/>
2 | 2 | 2 | 0 | 2
<br/>
0 | 0 | 0 | 0 | 2
<br/>

**_요렇게 진행하게 되는 것_**
<br/>

빙 돌아서 진행하게 됌. 그렇다고 DFS을 이용하면 11칸이 안나오는 것은 아님. 별도의 작업이 들어가야함

```swift
func DFS(_ currentX: Int, _ currenty: Int, _ level: Int) {
    if currentX == 목적지x && currentY == 목적지y {
        answer = min(answer, level)
        // 이 문제로 적용하려면 dist 2차원 배열에 자취를 남겨서 비교해야되는 데..
        // 예시이니 생략...
    }
}
```

이렇게 목적지에 다 도달한 케이스에서 최솟값을 필터링 해주는 작업를 추가해줘야함
<br/>

만약 문제의 시간제한이 넉넉하면 상관없겠지만 그렇다고 좋은 코드라고는 할 수 없음
<br/>

그래서 우선 여기서 BFS를 이용하면 간단히 해결할 수 있음
<br/>

트리 구조로 BFS/DFS 비교는 너무 유명해서 생략(나중에 작성하게 될수도....)
<br/>

즉 문제 설명 그림을 보고 바로 BFS써야겠네 란 생각이 들어야했던 문제임
<br/>

게임 캐릭터의 자취를 남길 이차원 배열을 선언해줌

```swift
var dist = Array(repeating: Array(repeating: 0, count: maps.count), count: maps.count)
```

위 선언한 이차원 배열에 큐로 BFS의 자취를 넣어주면 되는 것
<br/>

```swift
    // 너비우선탐색
    func BFS(_ currentY:Int, _ currentX: Int) -> Int {
        // 사용할 큐를 임의로 만들어줌
        var que:[[Int]] = [[currentY, currentX]]
        dist[currentY][currentX] = 1

        while que.count > 0 {
            let cur = que.first! // 옵셔널 조심
            que.removeFirst() // 선입선출

            // 상하좌우 탐색
            for i in 0..<4 {
                // 다음 이동할 좌표들
                let ny = cur[0]+dy[i]
                let nx = cur[1]+dx[i]


                // 범위 내인지 체크
                if ny < 0 || nx < 0 || ny >= N || nx >= N {
                    continue
                }

                // 벽인 경우이거나 재방문인 경우
                if maps[ny][nx] == 0 || dist[ny][nx] != 0 {
                    continue
                }

                // 자취 처리
                dist[ny][nx] = dist[cur[0]][cur[1]] + 1
                que.append([ny, nx])
            }
        }

        // 마지막 위치 반환
        return dist[N-1][N-1]
    }
```

## 최종 코드

스위프트

```swift
func solution(_ maps:[[Int]]) -> Int {
    var answer:Int = 0
    let N:Int = maps.count // 정방행렬이니

    // 거리 자취를 담을 배열
    var dist = Array(repeating: Array(repeating: 0, count: N), count: N)
    //  상하좌우
    let dy = [-1, 1, 0, 0]
    let dx = [0, 0, -1, 1]

    // 너비우선탐색
    func BFS(_ currentY:Int, _ currentX: Int) -> Int {
        // 사용할 큐를 임의로 만들어줌
        var que:[[Int]] = [[currentY, currentX]]
        dist[currentY][currentX] = 1

        while que.count > 0 {
            let cur = que.first! // 옵셔널 조심
            que.removeFirst() // 선입선출

            // 상하좌우 탐색
            for i in 0..<4 {
                // 다음 이동할 좌표들
                let ny = cur[0]+dy[i]
                let nx = cur[1]+dx[i]


                // 범위 내인지 체크
                if ny < 0 || nx < 0 || ny >= N || nx >= N {
                    continue
                }

                // 벽인 경우이거나 재방문인 경우
                if maps[ny][nx] == 0 || dist[ny][nx] != 0 {
                    continue
                }

                // 자취 처리
                dist[ny][nx] = dist[cur[0]][cur[1]] + 1
                que.append([ny, nx])
            }
        }

        // 마지막 위치 반환
        return dist[N-1][N-1]
    }

    answer = BFS(0,0)
    // 문제 조건 조심
    return answer == 0 ? -1 : answer
}
```

C++

```swift
#include<vector>
#include <queue>

using namespace std;

typedef struct {
    int y,x;
} Me;

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

vector<vector<int>> dist;

int BFS(vector<vector<int>>& maps, int r, int c) {
    queue<Me> que;
    dist = vector<vector<int>> (r, vector<int> (c, 0));

    que.push({0,0});
    dist[0][0] = 1;

    while(!que.empty()) {
        Me cur = que.front();
        que.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;

            if (dist[ny][nx] != 0 || maps[ny][nx] == 0)
                continue;

            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            que.push({ny, nx});
        }
    }

    return dist[r - 1][c - 1] != 0 ? dist[r - 1][c - 1] : -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int row = maps.size(), col = maps[0].size();

    answer = BFS(maps, row, col);
    return answer;
}
```
