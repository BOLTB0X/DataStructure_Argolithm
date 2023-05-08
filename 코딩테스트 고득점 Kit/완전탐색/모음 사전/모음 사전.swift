import Foundation

func solution(_ word:String) -> Int {
    var answer:Int = 0 // 정답
    var moum:[String] = ["A", "E", "I","O","U"] // 모음 배열
    var candiWord:[String] = [] // 단어사전
    
    // 깊이우선탐색
    // 단어 하나씩 중복허용한 상태로 진행
    func DFS(_ cur:String, _ limit:Int , _ depth: Int) {
        // 탈출 조건
        if depth == limit {
            if candiWord.contains(cur) == false {
                candiWord.append(cur)
            }
            return
        } else {
            // 단어 만들기
            for m in moum {
                var next = cur // 매개변수는 let이므로
                next.append(m) // 추가하고
                // 다시 호출
                DFS(next, limit, depth+1)
            }
        }
    }
    
    // 길이 1부터 5까지 진행
    for i in 1...5 {
        DFS("", i, 0) // 호출
    }
    
    // 정렬
    // 문자열인 경우 아스키코드 문자열 앞들을 기준으로 하므로
    // A AA 이런식으로 정렬 됌
    candiWord = candiWord.sorted(by: <)
    
    // firstIndext 이용
    // 옵셔널이므로 강제추출 후 + 1
    answer = candiWord.firstIndex(of: word)! + 1
    return answer
}