# 고득점 kit > 완전탐색 > 모음 사전

## 문제

Level 2
<br/>
문제링크 : https://school.programmers.co.kr/learn/courses/30/lessons/84512?language=swift
<br/>
문제설명, 제한사항 생략
<br/>

## Intro

> 사전에서 첫 번째 단어는 "A"이고, 그다음은 "AA"이며, 마지막 단어는 "UUUUU"입니다.
> <br/>

탐색 말고 또 할게 있구나?
<br/>

## 풀이

알파벳 모음 'A','E','I','O','U'만을 사용하여 만들 수 있는, 길이 5 이하인 모든 단어 사전이 있을 때 input으로 들어오는 단어는 먗번 째에 있냐를 묻는 문제
<br/>

저 모을 갖고 단어를 만드는 것은 DFS로 만들 수 있음
<br/>

```swift
func DFS(_ cur:String, _ level:Int, _ size: Int) {
    if level == size {
        words.insert(cur) // 중복을 거르기 위해
        return
    }

    for i in 0..<5 {
        var next = cur
        next += moum[i]
        DFS(next, level+1, size)
    }
    return
}
```

DFS로 중복순열을 만드는 것처럼 구현하면 됌
<br/>

여기서 차이점은 원하는 길이에 도달한 문자열 "cur"를 words란 집합(set)에 넣어준다는 것임
<br/>

### set을 쓰는 이유

생각을 해보면 최대 길이 별 생성되는 단어들은
<br/>

```swift
길이 1 : ["E", "U", "A", "I", "O"]

길이 2 : ["UO", "IU", "EA", "UA", "U", "A", "EO", "AO", "UI", "OO", "EE", "OU", "AI", "OI", "OE", "OA", "IE", "AE", "AU", "IO", "AA", "O", "UE", "UU", "IA", "E", "EI", "II", "EU", "I"]
```

이런식으로 DFS의 size를 2로 해주면 또 길이가 1인 단어들이 중복해서 추가됌
<br/>

만약 words를 일반 배열로 선언했다면

```swift
if level == size {
    // 중복을 거르기 위해
    if words.contains(cur) == false  {
        words.append(cur)
    }
    return
}
```

이런식으로 또 조건문을 추가해야함
<br/>

---

다시 문제로 돌아와서 words(집합)에 완성된 단어들은 출력해보면

```swift
["OOAIO", "OUOUI", "IAUEI", "IUIIA", "IIAEE", "AAUIA", "UUIAE", "IUAAO", "OIUE", "AUAAI", "EIEU", "EAOOU", "IOEUE", "OEIEE", "EUEIU", "EEAUO", "IEEEE", "UOAAU", "IEOIE", "OOUEO", "OOOIA", "IAUUI", "IOEUU", "EIAEU", "AOIUI", "UOIEE", "IIEEU", "UAAOE", "AOU", "UEAEO", "IAOEE", "EIEIA", "IUIEE", "OEOOU", "EIOEA", "IIEAA", "OUIIA", "OAIAA", "OOOAI", "IUAUA", "UIIUA", "AAAIA", "IOUE", "UEEU", "AEOAE", "EOAOE", "EOOIO", "EEOUA", "AIOEU", "EUAOO".......]
```

이런식으로 뒤죽박죽으로 출력됌
<br/>

문자열을 정렬을 할때 sorted의 특성상 아스키코드로 정렬을 해주기에 오름차순으로 정렬을 하면 알아서 A AA AAA... 정렬를 해줌

```swift
words.map{String($0)}.sorted(by: <)
```

마지막으로 파라미터로 전달 받은 word의 인덱스에서 +1해주면 끝나는 문제임
<br/>

```swift
answer = wordsArr.firstIndex(of: word)!+1 // 옵셔널 조심
```

위 방식들을 정리하면 다음과 같음
<br/>

1. for문으로 길이 1부터 5까지 DFS 실행
   <br/>

2. DFS의 탈출 조건에 만들어낸 문자열을 set형에 insert
   <br/>

3. 문제 조건을 따르기 위해 오름차순 정렬 뒤 firtstIndex으로 인덱스를 찾고 +1해줌
   <br/>

## 최종 코드

스위프트

```swift
import Foundation

func solution(_ word:String) -> Int {
    var answer:Int = 0

    let moum:[String] = ["A","E","I","O","U"]
    var words = Set<String>()

    func DFS(_ cur:String, _ level:Int, _ size: Int) {
        if level == size {
            words.insert(cur)
            return
        }

        for i in 0..<5 {
            var next = cur
            next += moum[i]
            DFS(next, level+1, size)
        }
        return
    }

    for i in 1...5 {
        DFS("", 0, i)
    }

    let wordsArr = words.map{String($0)}.sorted(by: <)
    answer = wordsArr.firstIndex(of: word)!+1
    return answer
}
```

C++

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string moum = "AEIOU";
vector<string> candi;

void DFS(string cur, int level) {
    if (cur.length() == level) {
        candi.push_back(cur);
        return;
    }

    for (int i = 0; i < 5; ++i) {
        DFS(cur + moum[i], level);
    }
}

int solution(string word) {
    int answer = 0;

    for (int i = 1; i <= 5; ++i) {
        DFS("", i);
    }

    sort(candi.begin(), candi.end());

    for (auto c : candi) {
        if (c == word)
            break;
        answer++;
    }
    return answer + 1;
}
```
