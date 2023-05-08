# 고득점 kit > DFS/BFS > 타겟넘버

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/43165
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

**_전형적인 DFS 탐색 문제_**
<br/>
잘 생각해보면 방문리스트(visited) 또한 만들 필요가 없었음
<br/>

## 풀이

> -1+1+1+1+1 = 3
> <br/>
> +1-1+1+1+1 = 3
> <br/>
> +1+1-1+1+1 = 3
> <br/>
> +1+1+1-1+1 = 3
> <br/>
> +1+1+1+1-1 = 3
> <br/>

즉 배열 원소들을 각각 더하기, 빼기를 해서 target 값이 나오는 수를 세는 것이 핵심임 문제
<br/>

여기서 순열을 생각했었음, 왜냐 배열을 ABCDE으로 생각해보면
<br>

ABDCE, AECBD, 이런식으로 순서를 바꿔 target값이 나오나 했음 하지만 문제의 **_"핵심은 원소의 순서를 바꾸는게 아닌 더하거나 빼라는 것"_**
<br/>

원소들의 순서를 바꿔 새로운 배열을 만들어 다시 어디서 빼고 더하기는 비효율적임 하지만 고장된 배열에 무식하긴 하지만 매 순간 더하는 재귀, 빼는 재귀를 진행시켜 그 거의 최종 값만 확인 하면 되는 것
<br/>

즉 visited같은 방문리스트가 필요 없는 문제
<br/>

```swift
func DFS(_ tot: Int, _ level: Int) {
        // 도달했다면
        if level == numbers.count {
            if target == tot {
                answer += 1
            }
            return
        }

        DFS(tot+numbers[level],level+1)
        DFS(tot-numbers[level],level+1)
    }
```

그나마 조심해야할 부분은 바로 dfs의 깊이를 나타내는 level -> 현재 위치의 더해주고 그 다음 level+1으로 호출해줘야함
<br/>

인덱스의 특성상 길이가 7이면 인덱스들은 (0,1,2,3,4,5,6)임을 깜빡해서는 안됌
<br/>

## 최종 코드

스위프트

```swift
import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var answer:Int = 0

    // 깊이우선탐색
    func DFS(_ tot: Int, _ level: Int) {
        // 도달했다면
        if level == numbers.count {
            if target == tot {
                answer += 1
            }
            return
        }

        DFS(tot+numbers[level],level+1)
        DFS(tot-numbers[level],level+1)
    }

    DFS(numbers[0], 1)
    DFS(-numbers[0], 1)
    return answer
}
```

<br/>

c++

```cpp
#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& numbers, int target, int tot, int level, int &answer) {
    if (level == numbers.size()) {
        if (tot == target)
            answer++;
        return;
    }

    DFS(numbers, target, tot + numbers[level], level + 1, answer);
    DFS(numbers, target, tot - numbers[level], level + 1, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    DFS(numbers, target, 0, 0, answer);
    return answer;
}
```
