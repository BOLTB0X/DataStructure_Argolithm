# 고득점 kit > 탐욕법(Greedy) > 큰 수 만들기

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42883
문제설명, 제한사항 생략
<br/>

## Intro

어떻게 단순 무식하게 지금만 효율적으로 생각할까
<br/>

## 풀이

정말 문제 이름 그대로 큰 수 만들기이면 number 문자열 원소 중에서 큰수만 고르면 될것 같지만
<br/>

문제 설명에서
<br/>

> 예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다.
> <br/>

이는 기존 문자열 진행방향을 고정으로 큰 수를 선택해야한다는 것을 알수 있음
<br/>

즉 그냥 그리디라는 것
<br/>

제한 조건이
<br/>

> number는 2자리 이상, 1,000,000자리 이하인 숫자입니다.
> <br/>

이므로 해당 수가 제일 큰지 확인하는 2중 for문을 쓰기가 얘매함
<br/>

스택를 이용하여 뒤를 고려하지 않고 일단 스택에 넣은 수가 작으면 스택에서 pop하고 그걸 k수만 큼 지우면 되는 것이었음
<br/>

```python
for num in number:
    while stack and k > 0 and num > stack[-1]:
        stack.pop()
        k -= 1
    stack.append(num)
```

<br/>

만약에 number 문자열이 계속 작아지는 경우에 K가 0이 안되었을 경우를 대비해
<br/>

```python
if k > 0:
    stack = stack[:len(stack)-k]
```

으로 해결할 수 있음

<br/>

## 제출 코드

```python
def solution(number, k):
    answer = ''
    stack = []

    for num in number:
        while stack and k > 0 and num > stack[-1]:
            stack.pop()
            k -= 1
        stack.append(num)

    if k > 0:
        stack = stack[:len(stack)-k]
    answer = "".join(stack)
    return answer
```

<br/>

```swift
import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var answer:String = ""
    var number = number.map { String($0) }
    var k = k
    var stack:[String] = []

    for n in number {
        while !stack.isEmpty && stack.last! < n && k > 0 {
            stack.removeLast()
            k -= 1
        }
        stack.append(n)
    }

    // 다 안지워질수도 있으므로
    if k > 0 {
        stack = Array(stack[0..<stack.count-k])
    }

    answer = stack.joined()
    return answer
}
```
