# 고득점 kit > 정렬 > K번쨰 수

## 문제

Level 1
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/42748
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

기본적인 정렬문제. 문제를 잘 읽고 주어진 조건되로 풀면 쉽게 풀 수 있는 문제임
<br/>

## 풀이

```swift
func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
}
```

위 함수에 매개변수중 commands를 주어진 조건 되로 처리하면 됌
<br/>

먼저 명령을 하나씩 확인해야하니 for문을 돌림
<br/>

```swift
for idx in 0..<commands.count
```

문제 조건을 보면
<br/>

> 예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면
> <br/>
> array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
> <br/>
> 1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
> <br/>
> 2에서 나온 배열의 3번째 숫자는 5입니다.
> <br/>

```swift
for idx in 0..<commands.count {
    let i = commands[idx][0]
    let j = commands[idx][1]
    let k = commands[idx][2]

    let arr = array[i-1...j-1].sorted() // c++랑 다르게 이건 편했음
    answer.append(arr[k-1])
}
```

commands의 열은 3으로 고정, 차레로 부분 배열을 뽑을 i와 j, 새로 만들 k을 선언해줌
<br/>

중간에 인덱스(0부터 시작) 조심하고 범위대로 뽑고 오름차순 정렬해주면 끝
<br/>

## 최종 코드

스위프트

```swift
import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var answer:[Int] = [] // 정답

    for idx in 0..<commands.count {
        let i = commands[idx][0]
        let j = commands[idx][1]
        let k = commands[idx][2]

        let arr = array[i-1...j-1].sorted()
        answer.append(arr[k-1])
    }

    return answer
}
```

<br/>

C++

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto& cmd: commands) {
        vector<int> tmp;
        for (int i = cmd[0] - 1; i <cmd[1]; ++i) {
            tmp.push_back(array[i]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[cmd[2] - 1]);
    }
    return answer;
}
```
