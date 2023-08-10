# 고득점 kit > 완전탐색 > 피로도

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/87946
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

순열
<br/>

## 풀이

문제에서 핵심은 딱 이 문구임
<br/>

> 각 던전마다 탐험을 시작하기 위해 필요한 "최소 필요 피로도"와 던전 탐험을 마쳤을 때 소모되는 "소모 피로도"가 있습니다.
> <br/>
> 예를 들어 "최소 필요 피로도"가 80, "소모 피로도"가 20인 던전을 탐험하기 위해서는 유저의 현재 남은 피로도는 80 이상 이어야 하며, 던전을 탐험한 후에는 피로도 20이 소모됩니다.
> <br/>

즉 현재 배열의 첫번째를 맞닥 드린다면 현재 체력이 최소 필요 피로도보다 커야하고 이동 후 소모 피로도 만큼 체력이 깎임
<br/>

> 유저의 현재 피로도 k와 각 던전별 "최소 필요 피로도", "소모 피로도"가 담긴 2차원 배열 dungeons 가 매개변수로 주어질 때, 유저가 탐험할수 있는 최대 던전 수
> <br/>

즉 "최소 필요도"를 확인하고 체력을 깎여가며 진행할 때 저 배열을 어떻게 순회해야지 많이 진행할 수 있는지를 묻는 문제
<br/>

**_여기서 DFS로 순열하듯히 풀면 해결이 가능_**

먼저 던전을 순열로 나올수 있는 것들을 다 만들어 줌
<br/>

```python
from itertools import permutations

for per in permutations(dungeons, len(dungeons)):
```

<br/>

스위프트는 지원라이브러리가 없으니 DFS로 만 인덱스들을 담도록 작성
<br/>

```swift
func permutation(per: [Int], depth: Int) {
    if depth == dungeons.count {
        perArr.append(per)
        return
    }

    for i in 0..<dungeons.count {
        if visited[i] {
            continue
        }

        visited[i] = true
        permutation(per: per+[i], depth: depth+1)
        visited[i] = false
    }
    return
}
```

<br/>

이제 문제 완전탐색을 해주면 끝
<br/>

## 최종 코드

```swift
import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer:Int = 0
    var visited: [Bool] = Array(repeating: false, count: dungeons.count)
    var perArr:[[Int]] = []

    func permutation(per: [Int], depth: Int) {
        if depth == dungeons.count {
            perArr.append(per)
            return
        }

        for i in 0..<dungeons.count {
            if visited[i] {
                continue
            }

            visited[i] = true
            permutation(per: per+[i], depth: depth+1)
            visited[i] = false
        }
        return
    }

    permutation(per:[], depth: 0)

    for per in perArr {
        var cnt:Int = 0
        var cur:Int = k

        for p in per {
            if dungeons[p][0] > cur {
                continue
            }

            cnt += 1
            cur -= dungeons[p][1]
        }

        answer = max(answer, cnt)
    }
    return answer
}
```

<br/>

```python
from itertools import permutations


def solution(k, dungeons):
    answer = -1

    for per in permutations(dungeons, len(dungeons)):
        cur = k
        cnt = 0
        for p in per:
            if p[0] <= cur:
                cnt += 1
                cur -= p[1]

        answer = max(answer, cnt)
    return answer

```
