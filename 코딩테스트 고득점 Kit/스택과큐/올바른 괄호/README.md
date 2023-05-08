# 고득점 kit > 스택 / 큐 > 올바른 괄호

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/12909
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

뭐여 왜 시간초과여
<br/>

## 풀이

괄호를 문제설명과 문제 설명 중

> '(' 문자로 열렸으면 반드시 짝지어서 ')' 문자로 닫혀야 한다는 뜻입니다. 예를 들어
> <br/>
> "()()" 또는 "(())()" 는 올바른 괄호입니다.
> <br/>
> ")()(" 또는 "(()(" 는 올바르지 않은 괄호입니다.
> <br/>

이 것만 읽어보아도 스택을 사용해야한다는 것을 알 수 있음
<br/>

물론 그냥 완전탐색으로 풀 수 있음
<br/>

먼저 스택을 이용하던가 완전탐색을 사용하던 같은 접근 법임
<br/>

```swift
for 문자 in 문자열 {
    if  "(" 인 경우 {

    } else { ")" 인 경우

    }
}
```

위 의사코드에서 "("일때와 ")"을 나눠 진행하면 됨
<br/>

1. Stack을 이용할 경우
   **_스택의 선입후출 특성을 이용_**
   ()()(((()))()()) 이 괄호 문자열을 보고 왼쪽에서 오른쪽으로 진행하며 ")"을 맞닥드릴때를 생각해보면
   <br/>
   처음 )을 보면 앞에 (이 있으니 패스
   <br/>
   (((( 이 연속으로 나오면 올바른 괄호는 연속으로 )))) 이 나오는 것을 알수 있음
   <br/>
   그렇다면 (((( 을 하나씩 스택에 쌓아 올려두다 ")"을 맞닥드릴때 마다 하나씩 짝이 맞는 지 확인하며 맞으면 스택을 pop하고 아니면 올바른 괄호가 아니니 그냥 false를 리턴하면 되는 것
   <br/>
   이를 코드에 적용해보면 "("인 경우에 스택안에 넣어두고, ")"가 나온 경우 또 if else로 나눠 계속 진행인지 false인지 체크하면 됨
   <br/>
   else 구문 안에 또다른 if-else 조건
   <br/>
   처음 시간초과가 나왔을 때는 if-else는 if의 조건이 스택이 비어있지 않고 스택의 top이 "("인지를 체크하는 것이였음
   <br/>
   기존 index 관련 메소드들은 시간복잡도가 O(n)임 그렇다면 최악의 경우 2중 포문처럼 연산이 되는 효율성검사에 시간초과가 나와서 if-else 구조를 다시 생각해야 했음
   <br/>
   **_애초에 ")"이 나왔는데 스택이 비어있다는 것은 "()"의 짝이 맞지 않다는 것_** 을 떠올리고 if 조건을 심플하개 바꾸고 false를 반환
   <br/>
   그 외인 경우는 짝이 맞으니 pop() 이용
   <br/>
   거기다 for문 탐색 후 스택이 비어있지 않으면 올바른 괄호가 아닌것을 체크하면 되는 것
   <br/>

```swift
// 스택이 비어있다면
if stack.isEmpty == true {
    return false // 올바른 괄호가 x
} else { // 짝이 있으니
    stack.pop() // pop해줌
}
```

2. 완전탐색으로 풀기
   어찌보면 스택으로 푸는 것보다 매우 간단함
   <br/>
   입출력 예시를 봐보면
   <br/>
   "()()"
   <br/>
   "(())()"
   <br/>
   ")()("
   <br/>
   "(()("
   <br/>

   "("과 ")"의 갯수가 같은거이 올바른 괄호임 -> **_프로퍼티 하나 선언해서 오픈이면 + close이면 -로 진행하면 쉽게 해결 가능_**
   <br/>

```swift
for ch in _s {
    // 열림이면
    if ch == "(" {
        bracketCount += 1
    } else { // 닫힘이면
        bracketCount -= 1
    }

     // 만약 괄호가 0보다 작아지면 즉, 괄호가 맞지 않다는 뜻
    if bracketCount < 0 {
        return false
    }
}

// 다 끝난후에도 괄호가 남아있다면
if bracketCount != 0 {
    return false
}

return true
```

## 최종 코드

스위프트(스택)

```swift
import Foundation

struct Stack<T> {
    private var stack: [T] = []

    public var size: Int {
        return stack.count
    }

    public var isEmpty: Bool {
        return stack.isEmpty
    }

    public mutating func push(_ element: T) {
        stack.append(element)
    }

    public mutating func pop() -> T? {
        return stack.popLast()
    }

    public mutating func top() -> T? {
        return stack.last
    }
}

func solution(_ s:String) -> Bool {
    var stack = Stack<Int>() // 스택

    for i in s {
        // open이면
        if i == "(" {
            stack.push(1) // 스택에 넣어줌
        } else { // close를 직면하는 경우
            // 스택이 비어있지 않고 open이 있는 경우
            if stack.isEmpty == true {
                return false
            } else {
                stack.pop()
            }
        }
    }

    if stack.isEmpty == false {
        return false
    }
    return true
}
```

<br/>

스위프트(완전탐색?)

```swift
import Foundation

func solution(_ s:String) -> Bool {
    let _s = Array(s) // 편의상
    var bracketCount = 0

    for ch in _s {
        // 열림이면
        if ch == "(" {
            bracketCount += 1
        } else { // 닫힘이면
            bracketCount -= 1
        }

        // 만약 괄호가 0보다 작아지면 즉, 괄호가 맞지 않다는 뜻
        if bracketCount < 0 {
           return false
        }
    }

    // 다 끝난후에도 괄호가 남아있다면
    if bracketCount != 0 {
        return false
    }

    return true
}
```

<br/>

C++(스택)

```cpp
#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;
    stack<char> st;

    for (auto & p : s) {
        if (p == '(')
            st.push(p);
        else {
            if (st.empty())
                return false;
            else if (st.top() == '(')
                st.pop();
        }
    }

    if (!st.empty())
        answer = false;
    else {
        answer = true;
    }

    return answer;
}
```
