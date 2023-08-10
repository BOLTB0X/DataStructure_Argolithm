# 고득점 kit > 완전탐색 > 소수 찾기

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42839
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

sqrt 킹받네
<br/>

## 풀이

> 각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return
> <br/>

문제에서 알 수 있듯히 문자열의 숫자들로 1 부터 문자열의 길이까지 나올수 있는 순열을 구하고 그 수가 소수인지 체크하면 되는 문제
<br/>

여기서 조심해야하는 것은 **순열로 만든 수들의 중복임**
<br/>

set형으로 중복을 제거하면 됌
<br/>

```swift
// DFS로 순열 구현
func DFS(array: [String], number: String, n: Int, level: Int) {
    // 탈출 조건
    if level == n {
        isPrime(number) // 알아서 중복 제거
        return
    }

    // 배열 순회
    for i in 0..<array.count {
        var new_array = array // var로 교체
        let str = new_array.remove(at: i) // 제거와 제거한 무자
        DFS(array: new_array, number: "\(number)\(String(str))", n: n, level: level + 1)
    }

    return
}

// 1부터 문자열의 길이까지 실행
for i in 1...numbers.count {
     DFS(array: numbersArr, number: "", n: i, level: 0)
}
```

<br/>

```python
for i in range(1, len(numbers) + 1):
    per_str = set(permutations(numbers, i))
    for per in per_str:
        tmp = ""
        for pe in per:
            tmp += pe
        candi.append(int(tmp))
```

<br/>

그런 다음 소수인지 체크해주면 됌
<br/>

```swift
func isPrime(_ num: String) {
    let num = Int(num)!
    var cnt = 0

    if num > 1 {
        for i in 2...num {
            if cnt > 1{
                break
            }
            if num % i == 0 {
                cnt += 1
            }
        }

        if cnt == 1 {
            // 3. 소수이면 Set에 추가합니다.
            answer.insert(num) // Set에 넣어주어 중복 제거
        }
    }
}
```

<br/>

```python
def is_prime(p):
    if p == 0 or p == 1:
        return False

    for i in range(2, int(math.sqrt(p)) + 1):
        if p % i == 0:
            return False
    return True
```

<br/>

## 제출 코드

```python
from itertools import permutations
import math

def is_prime(p):
    if p == 0 or p == 1:
        return False

    for i in range(2, int(math.sqrt(p)) + 1):
        if p % i == 0:
            return False
    return True

def solution(numbers):
    answer = 0
    candi = []

    for i in range(1, len(numbers) + 1):
        per_str = set(permutations(numbers, i))
        for per in per_str:
            tmp = ""
            for pe in per:
                tmp += pe
            candi.append(int(tmp))

    print(candi)
    for ca in set(candi):
        if is_prime(ca):
            answer += 1
    return answer
```

<br/>

```swift
import Foundation

func solution(_ numbers:String) -> Int {
    var answer: Set<Int> = [] // 정답 집합 중복 제거용
    var numbersArr = numbers.map{String($0)} // 편의를 위해

    func isPrime(_ num: String) {
        let num = Int(num)!
        var cnt = 0

        if num > 1 {
            for i in 2...num {
                if cnt > 1{
                    break
                }
                if num % i == 0 {
                    cnt += 1
                }
            }

            if cnt == 1 {
                // 3. 소수이면 Set에 추가합니다.
                answer.insert(num) // Set에 넣어주어 중복 제거
            }
        }
    }

    // DFS로 순열 구현
    func DFS(array: [String], number: String, n: Int, level: Int) {
        // 탈출 조건
        if level == n {
            isPrime(number) // 알아서 중복 제거
            return
        }

        // 배열 순회
        for i in 0..<array.count {
            var new_array = array // var로 교체
            let str = new_array.remove(at: i) // 제거와 제거한 무자
            DFS(array: new_array, number: "\(number)\(String(str))", n: n, level: level + 1)
        }

        return
    }

    // 1부터 문자열의 길이까지 실행
    for i in 1...numbers.count {
        DFS(array: numbersArr, number: "", n: i, level: 0)
    }
    return answer.count // 길이가 곹 갯수
}
```
