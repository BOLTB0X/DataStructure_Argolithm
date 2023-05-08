import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer: Int = 0
    // 방문리스트
    var visited: [Bool] = Array(repeating: false, count: 9)

    func DFS(cur: Int, board: [[Int]], depth: Int) {
        // 다 돌았다면
        if depth > answer {
            answer = depth
        }
        
        for i in 0..<board.count {
            // 재방문
            if visited[i] {
                continue;
            }
            
            // 현재가 최소필요도보다 크다면 재귀 호출
            if cur >= board[i][0] {
                visited[i] = true 
                DFS(cur: cur-board[i][1], board: board, depth: depth+1)
                visited[i] = false
            }
        }
        return
    }
    
    // dfs로 순열 시작
    DFS(cur: k, board: dungeons, depth: 0)
    return answer
}
