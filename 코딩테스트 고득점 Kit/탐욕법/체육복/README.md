# 고득점 kit > 탐욕법(Greedy) > 체육복

## 문제

Level 1
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42862
문제설명, 제한사항 생략
<br/>

## Intro

정말 기초적인 그리디 문제
<br/>

## 풀이

문제에서
<br/>

> 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다.
> <br/>
> 학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다.
> <br/>
> 예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다.
> <br/>

즉 해당 학생이 체육복을 빌려야하면 좌우 학생중 한명을 선택해서 빌리게 하면 되는 것
<br/>

1. 배열을 선언하여 학생들의 체육복 갯수를 확인
   <br/>

   ```python
    arr = [1]*n

    for l in lost: # 두고온 넘들
        arr[l-1] -= 1
    for r in reserve:
        arr[r-1] += 1
   ```

<br/>

2. 진행 방향을 선택하여 첫번째 학생과 마지막 학생만 조심해주고 좌우 확인
   <br/>

   ```python
   for i in range(len(arr)):
        if arr[i] == 0: # 체육복이 없다면
            if i > 0 and arr[i-1] >= 2:
                arr[i-1] -= 1
                arr[i] += 1

            elif i < n-1 and arr[i+1] >= 2: # 여분이 있다면
                    arr[i+1] -= 1
                    arr[i] += 1
   ```

<br/>

여기서 조건문의 인덱스에 대해 걸어 둔 것을 볼수 있음
<br/>

이는 만약 그리디 여서 일단 최고의 해를 선택하는 것이니 만약 앞 놈에게 못빌리고 뒷놈에게 빌릴 수 있디면 바로 다른 조건문에 걸리기 위해 **==**이 아닌 부등호를 사용하는 것
<br/>

## 제출 코드

```python
def solution(n, lost, reserve):
    answer = 0
    arr = [1]*n

    for l in lost: # 두고온 넘들
        arr[l-1] -= 1
    for r in reserve:
        arr[r-1] += 1

    for i in range(len(arr)):
        if arr[i] == 0: # 체육복이 없다면
            if i > 0 and arr[i-1] >= 2:
                arr[i-1] -= 1
                arr[i] += 1

            elif i < n-1 and arr[i+1] >= 2: # 여분이 있다면
                    arr[i+1] -= 1
                    arr[i] += 1

    for a in arr:
        if a > 0:
            answer += 1
    return answer
```

<br/>

```swift
import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var answer = 0
    // 학생들의 체육복 배열
    var students = [Int] (repeating: 1, count: n + 1)

    // 잃어버린 학생
    for l in lost {
        students[l] -= 1
    }

    // 여분
    for r in reserve {
        students[r] += 1
    }

    for i in 1..<n+1 {
        // 빌려야한 학생 발견
        if students[i] == 0 {
            // 앞에 학생에게 빌리는 경우
            if i > 1 && students[i - 1] > 1 {
                students[i - 1] -= 1
                students[i] = 1
            }

            // 뒤 애한테 빌리는 경우
            else if i < n && students[i + 1] > 1 {
                students[i + 1] -= 1
                students[i] = 1
            }
        }
    }

    answer = students.filter { $0 > 0 }.count-1 // 수업가능한 학생 카운트
    return answer // 배열의 편의를 위해 인덱스 + 1 했기 때문
}
```
