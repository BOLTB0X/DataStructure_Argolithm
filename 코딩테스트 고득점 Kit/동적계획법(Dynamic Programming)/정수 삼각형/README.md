# 고득점 kit > 동적계획법(Dynamic Programming) > 정수 삼각형

## 문제

Level 3
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/43105
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

점화식
<br/>

## 풀이

![삼각형](https://grepp-programmers.s3.amazonaws.com/files/production/97ec02cc39/296a0863-a418-431d-9e8c-e57f7a9722ac.png)
<br/>

> 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우를 찾아보려고 합니다.
> <br/>
> 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능합니다.
> <br/>

즉 대각선 이동을 배열 상으로 생각해보면
<br/>

7
<br/>
3 8
<br/>
8 1 0
<br/>
2 7 4 4
<br/>
4 5 2 6 5
<br/>

즉 양 대각선 이동을 (i+1, j), (i+1, j+1)으로 생각해야함
<br/>

삼각형을 거쳐간 숫자의 최댓값을 구해하므로 **DP**를 이용
<br/>

결국 마지막 행에 (i+1, j), (i+1, j+1) 중 최댓값 을 더해서 그 중 최댓값을 리턴해주면 되는 것
<br/>

1. 0행부터 시작이 아닌 1행부터 시작해 n-1행까지 진행
   <br/>

2. 열을 해당 행만큼 진행하는 데 **바로 위**, **바로 옆 뒤**, **둘 중에 큰 것**
   <br/>

```python
for i in range(1, len(triangle)):
    for j in range(i+1):
        if j == 0:
            triangle[i][j] += triangle[i-1][j]
        elif i == j:
            triangle[i][j] += triangle[i-1][j-1]
        else:
            triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1])
```

<br/>

## 최종 코드

```python
def solution(triangle):
    answer = 0

    for i in range(1,len(triangle)):
        for j in range(i+1):
            if j == 0:
                triangle[i][j] += triangle[i-1][j]
            elif i == j:
                triangle[i][j] += triangle[i-1][j-1]
            else:
                triangle[i][j] += max(triangle[i-1][j], triangle[i-1][j-1])

    answer = max(triangle[-1])
    return answer
```
