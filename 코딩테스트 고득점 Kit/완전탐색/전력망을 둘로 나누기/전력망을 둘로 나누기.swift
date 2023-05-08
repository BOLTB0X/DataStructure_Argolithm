import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    var answer: Int = Int.max
    // 인접행렬
    var adj: [[Int]] = Array(repeating: Array(repeating: 0,count:n+1 ), count: n+1)
    
    // 인접행렬 표시
    for i in 0..<wires.count {
        adj[wires[i][0]][wires[i][1]] = 1
        adj[wires[i][1]][wires[i][0]] = 1
    }
    
    // BFS
    func BFS(_ start: Int) -> Int {
        // 방문리스트
        var visited:[Bool] = Array(repeating: false, count: n+1)
        visited[start] = true
        
        var que = [start]
        var ret = 1 // 현재 스타트 포함
        
        // 큐가 비어질때까지
        while que.count > 0 {
            let cur = que.removeFirst()
            
            for i in adj[cur].enumerated() {
                // 연결되어 있고 미방문이면
                if i.1 == 1 && visited[i.0] == false {
                    visited[i.0] = true
                    que.append(i.0)
                    ret += 1
                }
            }
        }
        return ret
    }
    
    // 와이어를 하나씩 끈고 DFS 수행하며 최선의 정답 -> 최솟값 필요
    for i in 0..<wires.count {
        // 끊음
        adj[wires[i][0]][wires[i][1]] = 0
        adj[wires[i][1]][wires[i][0]] = 0
        
        let ret1 = BFS(wires[i][0])
        let ret2 = BFS(wires[i][1])
        
        // 최솟값 체크
        answer = min(answer, abs(ret1-ret2))
        // 원상복구
        adj[wires[i][0]][wires[i][1]] = 1
        adj[wires[i][1]][wires[i][0]] = 1
    }
    return answer
}