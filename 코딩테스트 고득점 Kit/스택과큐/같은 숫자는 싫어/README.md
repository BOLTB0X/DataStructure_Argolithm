# 고득점 kit > 스택 / 큐 > 같은 숫자는 싫어

## 문제

Level 1
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/12906
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

정말 스택문제
<br/>

## 풀이

정말 그냥 스택에 상단을 확인하며 코드를 작성하면 끝
<br/>

## 제출 코드

```swift
// 스위프트
import Foundation

func solution(_ arr: [Int]) -> [Int] {
    var answer:[Int] = [] // 정답
    var stack:[Int] = [] // 스택

    // 단순풀이
    for i in 0..<arr.count {
        if stack.count == 0 {
            st.append(arr[i])
            answer.append(arr[i])
        } else {
            // 같은 숫자를 보면
            if st.last == arr[i] {
                continue
            }
            // 다른 숫자이니 넣어줌
            st.append(arr[i])
            answer.append(arr[i])
        }
    }
    return answer
}
```

<br/>

```python
# 파이썬
def solution(arr):
    answer = []

    for a in arr:
        if len(answer) == 0 or (len(answer) > 0 and answer[-1] != a):
            answer.append(a)
        continue

    return answer
```

<br/>
