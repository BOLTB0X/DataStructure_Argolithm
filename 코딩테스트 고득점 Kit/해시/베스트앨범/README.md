# 고득점 kit > 해시 > 베스트앨범

## 문제

Level 3
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42579
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

문제를 이해하기가 빡셈
<br/>

## 풀이

문제를 읽고 이해하는 데 꽤 시간이 걸리는 문제
<br/>

> 1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
>    <br/>
> 2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
>    <br/>
> 3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
>    <br/>

이 조건을 딕셔너리를 이용하여 문제조건을 따라가면 됌
<br/>

나는 총 재생시간을 담은 'totalDic' 딕셔너리와 'indexDic' 딕셔너리 총 2개를 이용함
<br/>

### 1. **어느 장르가 많이 재생되었는지와 장르별 음악 고유번호**

```swift
// 스위프트
for i in 0..<genres.count {
    if let _ = totalDic[genres[i]] {
        totalDic[genres[i]]? += plays[i]
        indexDic[genres[i]]?.append(i)
    } else {
        totalDic[genres[i]] = plays[i]
        indexDic[genres[i]] = [i]
    }
}
```

<br/>

```python
# 파이썬
for i in range(len(genres)):
    if genres[i] in totalDic:
        totalDic[genres[i]] += plays[i]
        indexDic[genres[i]].append(i)
    else:
        totalDic[genres[i]] = plays[i]
        indexDic[genres[i]] = [i]
```

<br/>

### 2. 어느 장르가 많이 재생되었는지 확인

```swift
// 스위프트
let sortedTotalDic = totalDic.sorted {$0.value > $1.value}
```

<br/>

```python
# 파이썬
sortedGenres = sorted(totalDic.items(), key=lambda x: x[1], reverse=True)
```

<br/>

### 3. 문제 조건 2,3

정렬 기준을 plays 배열에 맞춰 진행
<br/>

```swift
// 스위프트
for (key, value) in sortedTotalDic {
    let sortedArr = indexDic[key]!.sorted { plays[$0] > plays[$1]}
    answer.append(sortedArr[0])
    if sortedArr.count > 1 {
        answer.append(sortedArr[1])
    }
}
```

<br/>

```python
# 파이썬
for genre in sortedGenres:
    sortedArr = sorted(indexDic[genre[0]],
                           key=lambda x: plays[x], reverse=True)
    answer.append(sortedArr[0])
    if len(sortedArr) > 1:
        answer.append(sortedArr[1])
```

## 최종제출

```swift
// 스위프트
import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var answer:[Int] = []
    var totalDic: [String:Int] = [:]
    var indexDic:[String: [Int]] = [:]

    for i in 0..<genres.count {
        if let _ = totalDic[genres[i]] {
            totalDic[genres[i]]? += plays[i]
            indexDic[genres[i]]?.append(i)
        } else {
            totalDic[genres[i]] = plays[i]
            indexDic[genres[i]] = [i]
        }
    }

    //print(totalDic)
    //print(indexDic)
    let sortedTotalDic = totalDic.sorted {$0.value > $1.value}

    for (key, value) in sortedTotalDic {
        let sortedArr = indexDic[key]!.sorted { plays[$0] > plays[$1]}
        answer.append(sortedArr[0])
        if sortedArr.count > 1 {
            answer.append(sortedArr[1])
        }
    }

    return answer
}
```

<br/>

```python
# 파이썬
def solution(genres, plays):
    answer = []
    totalDic = {}
    indexDic = {}

    for i in range(len(genres)):
        if genres[i] in totalDic:
            totalDic[genres[i]] += plays[i]
            indexDic[genres[i]].append(i)
        else:
            totalDic[genres[i]] = plays[i]
            indexDic[genres[i]] = [i]

    sortedGenres = sorted(totalDic.items(), key=lambda x: x[1], reverse=True)
    # print(sortedGenres)

    for genre in sortedGenres:
        sortedArr = sorted(indexDic[genre[0]],
                           key=lambda x: plays[x], reverse=True)
        answer.append(sortedArr[0])
        if len(sortedArr) > 1:
            answer.append(sortedArr[1])
    return answer

```

<br/>
