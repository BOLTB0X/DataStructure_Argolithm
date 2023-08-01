# 고득점 kit > 탐욕법(Greedy) > 다리를 지나는 트럭

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42583
문제설명, 제한사항 생략
<br/>

## Intro

컴퓨터의 입장이 되자
<br/>

## 풀이

큐를 이용하면서 무게 제한 안에 들면 넣어주고 아님 그냥 진행 시켜주면 됌
<br/>

```python
while cur < len(truck_weights): # 1
    if bridge and bridge[0][1] == bridge_length: # 2
        bridge.popleft()

    if sum(b[0] for b in bridge) + truck_weights[cur] <= weight: # 3
        bridge.append((truck_weights[cur], 0))
        cur += 1

    for _ in range(len(bridge)): # 4
        t1, t2 = bridge.popleft()
        bridge.append((t1, t2+1))
    answer += 1 # 5
```

<br/>

1. 위 코드 처럼 먼저 마지막 트럭을 넣을때 까지 while문을 돌림

2. 다리(큐)안에 있는 트럭(원소)가 다리 길이까지 도달 했으면 빼줌

3. 여기서 다리에 넣어줄지 안 넣어줄지를 결정함

4. 다리 안에 있는 트럭들을 진행률을 올려줌

5. 총 시간이니 while문이 돌때마다 타임 체크

<br/>

```python
return answer + bridge_length
```

위 과정에선 마지막 트럭의 시간을 고려해주지 못함 그러므로 다리 길이를 더 해야줘야 함
<br/>

## 제출 코드

```python
# 파이썬
from collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge = deque([])
    cur = 0

    while cur < len(truck_weights):
        if bridge and bridge[0][1] == bridge_length:
            bridge.popleft()

        if sum(b[0] for b in bridge) + truck_weights[cur] <= weight:
            bridge.append((truck_weights[cur], 0))
            cur += 1

        for _ in range(len(bridge)):
            t1, t2 = bridge.popleft()
            bridge.append((t1, t2+1))
        answer += 1

    return answer + bridge_length
```

<br/>

```swift
// 스위프트
func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var answer:Int = 0 // 경과시간
    var que = Array(repeating: 0, count: bridge_length)
    var curIndex: Int = 0
    var totalWeight: Int = 0 // 다리의 무게

    while curIndex < truck_weights.count {
        // 시간 경과처리
        answer += 1
        totalWeight -= que.removeFirst()

        // 다리에 트럭을 더 올릴 수 있는 경우
        if totalWeight+truck_weights[curIndex] <= weight {
            totalWeight += truck_weights[curIndex]
            que.append(truck_weights[curIndex])
            curIndex += 1 // 트럭이 들어가니 인덱스도 증가시켜줌

        } else {
            que.append(0) // 그냥 시간처리 용
        }
    }
    return answer+bridge_length
}
```
