# 고득점 kit > 스택 / 큐 > 주식 가격

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42584
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

완전탐색이 아니네
<br/>

## 풀이

문제 입출력 예 설명에서
<br/>

> 1초 시점의 ₩1은 끝까지 가격이 떨어지지 않았습니다.
> <br/>
> 2초 시점의 ₩2은 끝까지 가격이 떨어지지 않았습니다.
> <br/>
> 3초 시점의 ₩3은 1초뒤에 가격이 떨어집니다. 따라서 1초간 가격이 떨어지지 않은 것으로 봅니다.
> <br/>
> 4초 시점의 ₩2은 1초간 가격이 떨어지지 않았습니다.
> <br/>
> 5초 시점의 ₩3은 0초간 가격이 떨어지지 않았습니다.
> <br/>

즉 현재 가격정보를 담은 배열(인덱스가 시간이라 할 때) 언제까지 가격이 안정화인지 확인해 원소를 넣어주면 됌
<br/>

처음에는 왼쪽에서 오른쪽으로 진행해서 0번째 부터 가격을 일일히 확인할까 했음
<br/>

문제 예시에서 알 수 있듯히 처음에 있던걸 하락하기 시작할 때 그 때부터 하락하는지 확인해주면 되는 것
<br/>

```python
for i in range(1, len(prices)):
    # 하락
    while stack and prices[stack[-1]] > prices[i]:
        j = stack.pop()
        answer[j] = i - j
    stack.append(i)
```

<br/>

즉 상승세 일때는 그냥 스택에 넣어주었다가 낮춰 졌을 때 for문으로 진행한 i와 스택에 넣어났던 것의 차이 해당 배열에 넣어주면 되는 것
<br/>

## 제출 코드

```python
def solution(prices):
    answer = [i for i in range(len(prices)-1,-1,-1)]
    stack = [0]

    for i in range(1, len(prices)):
        # 하락
        while stack and prices[stack[-1]] > prices[i]:
            j = stack.pop()
            answer[j] = i - j
        stack.append(i)
    return answer
```
