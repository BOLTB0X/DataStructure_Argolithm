# 고득점 kit > 스택 / 큐 > 프로세스

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42587
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

맞으면 그만, 아니면 뒤로
<br/>

## 풀이

**큐의 선입선출(first in, first out)을 이용해서 풀이**
<br/>

처음에 정렬을 시킨 뒤 첫번째 원소를 확인하는 방법을 생각했음
<br/>

하지만 이 방법은 그냥 정렬되고 location 값이 어디로 갔는지만 확인 되는 것이니 문제해결 불가
<br/>

문제에서
<br/>

> 1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
>    <br/>
> 2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
>    <br/>
> 3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
>    <br/>
>    3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.
>    <br/>

즉 첫 상단을 꺼내고 그것의 중요도가 제일 크거나 같은 경우에만 프로세스 안에 꺼내고 작으면 다시 넣주는 것을 반복하면 되는 것
<br/>

여기서 일반 큐와 우선순위 큐으로 가능함
<br/>

큐는 뽑은 값이 최댓값인지 아닌지를 체크해줘야하고 우선순위 큐는 그냥 나머지 원소들이랑 같은지만 확인하면 됌
<br/>

### 큐

```python
while dq:
    curVal, curIdx = dq.popleft()
    #print(curIdx, curVal)
    if dq and curVal < max(dq)[0]:
        dq.append((curVal, curIdx))
    else:
        answer += 1
        if curIdx == location:
            break
```

<br/>

### 우선순위 큐

```swift
while que.isEmpty == false {
    // (int,int)이므로 편의를 위해
    let cur = que.removeFirst()
    // 최상단과 중요도가 같다면
    if cur.1 == pq.first! {
        answer += 1

        // 탈출 조건
        if cur.0 == location {
            break
        }

        // 가장 중요도 높은 문서 pop
        pq.removeFirst()
    } else {
        // 최상단을 가장 하단으로 넘겨줌
        que.append(cur)
    }
}
```

## 제출 코드

```python
from collections import deque

def solution(priorities, location):
    answer = 0
    dq = deque([])

    for i in range(len(priorities)):
        dq.append((priorities[i], i))

    while dq:
        curVal, curIdx = dq.popleft()
        #print(curIdx, curVal)
        if dq and curVal < max(dq)[0]:
            dq.append((curVal, curIdx))
        else:
            answer += 1
            if curIdx == location:
                break

    return answer
```

<br/>

```swift
import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var answer:Int = 0
    // enumerated으로 인덱스와 값을 구분짓고 배열로 바꿈
    var que = priorities.enumerated().map{ ($0.offset, $0.element)}
    var pq = priorities.sorted(by: >) // 우선순위 큐

    // 큐가 비어질때 까지
    // 큐가에 위치와 값과 중요도 pq를 내두고
    // 원소를 하나씩 pop해보면서 조건에 맞으면 카운트하고
    // 아니면 회전시킴
    while que.isEmpty == false {
        // (int,int)이므로 편의를 위해
         let cur = que.removeFirst()
        // 최상단과 중요도가 같다면
        if cur.1 == pq.first! {
            answer += 1

            // 탈출 조건
            if cur.0 == location {
                break
            }

            // 가장 중요도 높은 문서 pop
            pq.removeFirst()
        } else {
            // 최상단을 가장 하단으로 넘겨줌
            que.append(cur)
        }
    }
    return answer
}
```
