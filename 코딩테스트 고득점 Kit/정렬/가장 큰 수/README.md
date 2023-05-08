# 고득점 kit > 정렬 > 가장 큰 수

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42746?language=swift
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

처음에 문제를 읽다 그리디인가? 했던 문제
<br/>

다시 차분이 문제를 읽어보고 다른 사람들의 코드를 참고해서 푼 문제임
<br/>

## 풀이

<br/>

### 1차시도

입출력을 보고 그냥 아 고차함수 쓰면 되겄네~ 했다 미통과가 떴다
<br/>

```swift
// 1차
func solution(_ numbers:[Int]) -> String {
    return numbers.map{ String($0) }.sorted(by: >).joined()
}
```

sorted로 문자열을 하면 아스키코드를 기준으로 정렬이 됌
<br/>
이렇게 하면 입출력 예의 2번인 numbers: [3, 30, 34, 5, 9]의 리턴 값이 "9543303" 이 나와버림
<br/>
그냥 정렬을 할때 30 3, 20 2 이런 비교에서 통하지 않는 다는 것을 알게 됌
<br/>

그래서 계속 고민을 하다 정렬 조건을 바꿔야된다는 생각에 도달
<br/>

처음 C/C++처럼 첫번째 원소가 같으면 두번째를 비교해야하고, 길이가 다를때 한자리를 리턴으로 코드를 고민해보았다
<br/>

하지만 Swift 특성상 String 시퀀스 원소와 Charactor형의 오류이 있어 다른 풀이의 설명만 읽어보니 아이디어를 얻음
<br/>

```swift
"\(s1)"+"\(s2)" > "\(s2)"+"\(s1)"
```

여기서 무릎을 딱 쳤을 정도로 명쾌함을 느껴버림
<br/>

이런 구성이면 "303" "330"을 비교하면서 sorted가 정렬하니 이 문제의 핵심이라 생각하고 2차 시도를 함
<br/>

---

### 2차 시도

```swift
// 2차 시도
func solution(_ numbers:[Int]) -> String {
    // custom 정렬
    func cmp(_ s1:String, _ s2:String) -> Bool {
        return "\(s1)"+"\(s2)" > "\(s2)"+"\(s1)"
    }

    return numbers.map{ String($0) }.sorted(by: cmp).joined()
}
```

하지만 테스트 케이스 11번을 통과하지 못함
<br/>

그래서 문제를 다시 읽어보니 문제에서 문자열로 바꾸긴 해도 결국 제일 큰 수를 반환하는 것이었음 즉 만약 [0,0,0,0,0,0,0]인 경우에는 정답이 "0"이여야만 했음
<br/>

생각을 해보니 이 문제는 중간에 "30320", "5523053" 이런식에 중간에 0이 낄수 없는 문제였던 것
<br/>

그렇다면 0을 마지막을 제외하고 걸려내야했음
<br/>

---

### 3차 시도

체크용 변수 flag를 선언한 뒤 2차 시도에서 joined만 빼고 for문을 돌려서 "0"이 나오는 지 체크하며 나왔으면 0으로 바꿔줘야함
<br/>

그렇다면 맨 마지막에 0이 나오면 기것만든 정답이 0이 되지 않나 함 -> 이를 방지하기 위해 if 조건에 numbers[i] != 0 && flag == false를 걸음
<br/>

즉 정답이 0인 경우는 절때 첫 문자열 원소를 제외하고 나올 수가 없음
<br/>

```swift
for i in 0..<numbers.count {
    if numbers[i] != "0" && flag == false {
        flag = true
        answer = ""
    }

    if flag {
        answer += numbers[i]
    } else { // 000000 맞닥드린 것
        answer = "0"
    }
}
```

맨 처음에 0이 안나왔으면 그냥 for문으로 원소 넣어주는 방식을 쭉 진행하면 됌 -> 한 번 flag가 true가 되면 정답이 "0"되는 경우가 없다는 것
<br/>

---

## 최종 코드

```swift
import Foundation

func solution(_ numbers:[Int]) -> String {
    var answer: String = ""
    var flag: Bool = false // 체크용

    // custom 정렬
    func cmp(_ s1:String, _ s2:String) -> Bool {
        return "\(s1)"+"\(s2)" > "\(s2)"+"\(s1)"
    }

    var numbers = numbers.map{ String($0) }.sorted(by: cmp)

    for i in 0..<numbers.count {
        if numbers[i] != "0" && flag == false {
            flag = true
            answer = ""
        }

        if flag {
            answer += numbers[i]
        } else { // 000000 맞닥드린 것
            answer = "0"
        }
    }
    return answer
}
```
