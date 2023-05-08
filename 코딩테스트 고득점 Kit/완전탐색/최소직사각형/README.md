# 고득점 kit > 완전탐색 > 최소직사각형

## 문제

Level 1
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/86491
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

처음에 격자판에 1111이런식으로 직접 해봐야하나 했다 "level1 문제지~"하며 문제를 차분히 읽으며 해결한 문제
<br/>

## 풀이

문제를 읽다보면 명합을 가로로 눕힌다~, 세로로 눕힌다란 글에 정말 돌리는 걸 생각했었음
<br/>

문제 예시를 자세히 보면 결국 작은것 중 최고로 큰걸로 만들어줘이다
<br/>

1: 60 50
<br/>
2: 30 70
<br/>
3: 60 30
<br/>
4: 80 40
<br/>

문제 설명처럼 가로 중 제일 긴 80과 세로 중 제일 긴 70으로 하면 각 명함을 넣으면 여분이 많이 남아 비효율적이라는 것
<br/>

> 하지만 2번 명함을 가로로 눕혀 수납한다면 80(가로) x 50(세로) 크기의 지갑으로 모든 명함들을 수납할 수 있습니다.
> <br/>

이 말은 즉슨 2번 명함을 눕히면 (30 70) -> (70 30)으로 만들 수 있다는 뜻이고 50을 세로로 채택했다는 것은 세로 값들 중에 몇번 째 값으로 보기보단 가로 세로를 하나하나씩 확인해서 최소 값들을 모았다 그중에서 제일 큰 값이라는 뜻
<br/>

이를 코드로 나타내몀

```swift
var w: Int = -1
var h: Int = -1

for i in 0..<sizes.count {
    w = max(max(sizes[i][0], sizes[i][1]), w)
    h = max(min(sizes[i][0], sizes[i][1]), h)
    print("\(i) \(w) \(h)")
}
```

명함 하니씩 확인하여 가장 긴 값 중에 제일 큰값이 w(가로), 가장 짧은 값 중 제일 큰 값이 h(세로)로 하면 됌
<br/>

이를 코드를 이쁘게 정리하면

```swift
    for size in sizes {
        // 가로는 최댓값중 최대
        // 세로는 최솟값중 최대
        w = max(w, size.max()!)
        h = max(h, size.min()!)
    }
```

## 최종 코드

```swift
import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var w:Int = 0 // 가로
    var h:Int = 0 // 세로

    for size in sizes {
        // 가로는 최댓값중 최대
        // 세로는 최솟값중 최대
        w = max(w, size.max()!)
        h = max(h, size.min()!)

    }
    return w * h
}
```
