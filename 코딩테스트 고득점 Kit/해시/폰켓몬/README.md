# 고득점 kit > 해시 > 폰켓몬

## 문제

Level 1
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/86491
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

왜 해시일까?
<br/>

## 풀이

> 홍 박사님은 당신에게 자신의 연구실에 있는 총 N 마리의 폰켓몬 중에서 N/2마리를 가져가도 좋다
> <br/>

문제 설명과 입출력 예를 한 번 봐보자
<br/>

예시 1 [3,1,2,3] : 2
<br/>
최대한의 종류를 가져야 함 그런데 중복을 제거한 후 모두 가져도 2마리
<br/>

**_즉 가질 수 있는 종류는 2가지_**
<br/>

예시 2 [1,2,3,4,5,6] : 3
<br/>

중복된 게 없더라도 "총 N 마리의 폰켓몬 중에서 N/2마리"의 조건으로 가져가는 폰켓몬 3마리
<br/>

**_즉 가질 수 있는 종류는 2가지_**
<br/>

이를 코드로 나타내면

```swift
selected.count <= N ? selected.count : N
```

위 selected 배열에 중복이 없게끔 만들면 쉽게 푸는 문제였음
<br/>

## 최종 코드

swift 코드

```swift
import Foundation

func solution(_ nums:[Int]) -> Int {
    var answer:Int = 0
    let N:Int = nums.count/2 // 길의 반

    // 집합 이용
    var selected:Set<Int> = []

    for n in nums {
        selected.insert(n)
    }

    answer = selected.count <= N ? selected.count : N
    return answer
}
```

c++코드

```cpp
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int N= nums.size() / 2; // 길의 반

    // 중복을 없애기 위해 집합 이용
    set<int> selected;

    // 싹다 선택
    for (auto n: nums) {
        selected.insert(n);
    }

    answer = selected.size() <= N ? selected.size() : N;
    return answer;
}
```
