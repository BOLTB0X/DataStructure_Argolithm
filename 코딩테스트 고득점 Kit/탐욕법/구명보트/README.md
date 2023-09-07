# 고득점 kit > 탐욕법(Greedy) > 구명보트

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42885
문제설명, 제한사항 생략
<br/>

## Intro

문제를 읽자
<br/>

## 풀이

보트에 최대 두명까지만 탈 수 있는데 한계체중을 지키며 최소 보트를 타는 경우의 수를 구해야함
<br/>

처음 최대 두명을 놓쳐서 boat라는 배열을 생성해서 배열의 총합이 한계체중인지 체크헸지만
<br/>

계속해서 시간초과와 실패를 겪게 됌
<br/>

문제에서 집중해야 포인트는 딱 2개임
<br/>

> 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.
> <br/>
> 예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만
> <br/>

즉 people이란 배열의 순서대로 사람을 뽑을 필요가 없다는 것을 알 수 있음
<br/>

또한 스택 문제를 푸는 것처럼 스택이 비어질때가지 while문을 돌리는 것을 생각하고 문제에서 딱 2명만 탄다는 것을 캐치하면
<br/>

**오름차순 정렬**, **while**, **투 포인터처럼 그리디** 를 생각할 수 있음

```python
people.sort()
left, right = 0, len(people)-1

while left <= right:
    if people[left] + people[right] <= limit:
        left += 1
        right -= 1
    else:
        right -= 1
```

<br/>

최소 보트의 경우의 수이니 체중이 제일 작은 놈과 큰 놈을 보트에 태울 수 있는 지 없는 지 확인해야함
<br/>

만약 못태우면 제일 무거운 넘을 혼자태워 보내고 가능하면 둘 다 태워 보낸다 생각하면 해결할 수 있음
<br/>

## 제출 코드

```python
# 파이썬
def solution(people, limit):
    answer = 0
    people.sort()
    left, right = 0, len(people)-1

    while left <= right:
        if people[left] + people[right] <= limit:
            left += 1
            right -= 1
        else:
            right -= 1
        answer += 1
    return answer
```

<br/>

```swift
// 스위프트
import Foundation

func solution(_ people: [Int], limit: Int) -> Int {
    var answer: Int = 0
    var left: Int = 0
    var right: Int = people.count-1

    let people = people.sorted(by: <)

    while left <= right {
        if people[left]+people[right] <= limit {
            left += 1
            right -= 1
        } else {
            right -= 1
        }
        answer += 1
    }
    return answer
}
```
