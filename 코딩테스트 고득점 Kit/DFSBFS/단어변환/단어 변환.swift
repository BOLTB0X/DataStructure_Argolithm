import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var answer:Int = Int.max // 최솟값을 알기 위해 가장 최댓값으로 셋팅
    // 방문리스트
    var visited = Array(repeating: false, count: words.count)
    
    // 단어를 바꿀수 있는지 체크
    func check(_ word1:[String], _ word2:[String]) -> Bool {
        var cnt:Int = 0 // 다른 갯수
        
        for i in 0..<word1.count {
            // 단어가 다르다면
            if word1[i] != word2[i] {
                cnt += 1
            }
        }
        
        // 진행가능한지 
        return cnt == 1 ? true : false
    }
    
    // 깊이우선탐색 -> 순열처럼
    func DFS(_ cur:String, _ target:String, _ words:[String], _ depth:Int) {
        // 도달했다면
        if cur == target {
            // 삼항 연산자 이용
            answer = answer > depth ? depth : answer
            return
        } else {
            // 하나씩 진행
            for i in 0..<words.count {
                // 미방문이고 변환이 가능하다면
                if visited[i] == false && check(cur.map{String($0)}, words[i].map{String($0)}){
                    visited[i] = true // 방문처리
                    // 호출
                    DFS(words[i], target, words, depth+1)
                    visited[i] = false // 다른 케이스를 위해 미방문 처리
                } 
            }
        }
    }
    // dfs 진행
    DFS(begin, target, words, 0)

    // 반환
    return answer == Int.max ? 0 : answer
}