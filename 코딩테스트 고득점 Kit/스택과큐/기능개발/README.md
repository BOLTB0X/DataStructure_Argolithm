# 고득점 kit > 스택 / 큐 > 기능개발

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42586
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

맞으면 정답배열에 넣어주고, 아니면 증가
<br/>

## 풀이

문제에서
<br/>

> 프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.
> <br/>
> 또, 각 기능의 개발속도는 모두 다르기 때문에 뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고,
> <br/>
> 이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.

즉 예시 설명을 가져오면
<br/>

> 모든 기능이 하루에 1%씩 작업이 가능하므로, 작업이 끝나기까지 남은 일수는 각각 5일, 10일, 1일, 1일, 20일, 1일입니다.
> <br/>
> 어떤 기능이 먼저 완성되었더라도 앞에 있는 모든 기능이 완성되지 않으면 배포가 불가능합니다.
> <br/>
> 따라서 5일째에 1개의 기능, 10일째에 3개의 기능, 20일째에 2개의 기능이 배포됩니다.
> <br/>

즉 작업량을 큐에 넣고 큐의 최상단이 100을 넘으면 그때 배포가능한 갯수를 정답 배열에 넣어주면 되는 것
<br/>

```python
while pQue:
    while len(pQue) > 0 and pQue[0] >= 100:
        pQue.popleft()
        sQue.popleft()
        cnt += 1

    if cnt > 0:
        answer.append(cnt)
        cnt = 0

    for i in range(len(sQue)):
        pQue[i] += sQue[i]
```

## 제출 코드

```python
from collections import deque

def solution(progresses, speeds):
    answer = []
    cnt = 0

    pQue = deque([])
    sQue = deque([])

    for i in range(len(speeds)):
        pQue.append(progresses[i])
        sQue.append(speeds[i])

    while pQue:
        while len(pQue) > 0 and pQue[0] >= 100:
            pQue.popleft()
            sQue.popleft()
            cnt += 1

        if cnt > 0:
            answer.append(cnt)
            cnt = 0

        for i in range(len(sQue)):
            pQue[i] += sQue[i]

    return answer
```

<br/>

```swift
import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var answer:[Int] = [] // 정답
    var _p = progresses // 편의용
    var _speeds = speeds // 편의용

    // 진도율 _p가 비어지기 전까지 무한루프
    while _p.count > 0 {
        var cnt: Int = 0 // 매 루프 == 배포 주기
        // 작업 시작
        for i in 0..<_speeds.count {
            _p[i] += _speeds[i] // 진도
        }

        // 이제 배포가능한 게 있는지 체크
        // 있으면 가장 최상단 부터 체크
        while _p.count > 0 && _p[0] >= 100 {
            _p.removeFirst() // 큐처럼 삭제
            _speeds.removeFirst() // 큐처럼 삭제
            cnt += 1 // 카운트
        }

        if cnt > 0 { // 배포된 것이 존재하면
            answer.append(cnt) // 정답에 push
        }
    }
    return answer
}
```
