import Foundation

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    // 방문리스트
    var visited: [Bool] = Array(repeating: false, count: n)
    var answer: Int = 0 // 정답
    
    // 깊이우선 탐색
    func DFS(_ computers:[[Int]], cur: Int) {
        visited[cur] = true // 방문
        
        for i in 0..<n {
            // 연결되어있고 미방문이면
            if visited[i] == false && computers[cur][i] == 1 {
                // dfs
                DFS(computers, cur: i)
            }
        }
        return
    }
    
    // 하나씩 확인
    for i in 0..<n {
        if visited[i] == false { // 미방문 발견할때마다 카운팅
            DFS(computers, cur: i)
            answer += 1
        }
    }
    return answer
}