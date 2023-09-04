# 고득점 kit > 힙(Heap) > 더 맵게

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42626
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

힙이면 한번에 해결
<br/>

## 풀이

말 그대로 힙이면 한방에 해결하는 문제
<br/>

문제에서
<br/>

> 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 Leo는 스코빌 지수가 가장 낮은 두 개의 음식을 아래와 같이 특별한 방법으로 섞어 새로운 음식을 만듭니다.
> <br/>
> 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 \* 2)
> <br/>
> Leo는 모든 음식의 스코빌 지수가 K 이상이 될 때까지 반복하여 섞습니다.
> <br/>

즉 우선순위 큐에 넣고 문제 조건이 될때까지 반복문을 반복하면 됌
<br/>

```python
while pq[0] < K:
    heapq.heappush(pq, heapq.heappop(pq) + heapq.heappop(pq) * 2)
    answer += 1

    if len(pq) == 1 and pq[0] < K:
        answer = -1
        break
```

<br/>

## 제출 코드

```python
import heapq

def solution(scoville, K):
    answer = 0
    pq = []

    for s in scoville:
        heapq.heappush(pq, s)

    while pq[0] < K:
        heapq.heappush(pq, heapq.heappop(pq) + heapq.heappop(pq) * 2)
        answer += 1

        if len(pq) == 1 and pq[0] < K:
            answer = -1
            break
    return answer
```

<br/>
