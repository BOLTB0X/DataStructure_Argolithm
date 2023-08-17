// 2023 KAKAO BLIND RECRUITMENT 미로 탈출 명령어
import Foundation

func solution(_ n:Int, _ m:Int, _ x:Int, _ y:Int, _ r:Int, _ c:Int, _ k:Int) -> String {
    var answer:String = ""
    var board:[[String]] = Array(repeating: Array(repeating: ".",count: m+1), count: n+1)
    board[x][y] = "S"
    board[r][c] = "E"
    let dir:[[Int]] = [[1,0], [0,-1], [0,1], [-1,0]]
    let dStr:[String] = ["d", "l", "r", "u"]
    
    func DFS(cx: Int, cy: Int, cur: String, depth: Int) {
        if depth > k || answer != "" || abs(cx-r)+abs(cy-c)+depth > k {
            return
        }
        
        if depth == k && cx == r && cy == c{
            answer = cur
            return
        }
        
        for i in 0..<4 {
            let nx = cx + dir[i][0]
            let ny = cy + dir[i][1]
            
            if nx >= 1 && ny >= 1 && nx <= n && ny <= m && answer == "" {
                DFS(cx: nx, cy: ny, cur: cur + dStr[i], depth: depth+1)
            }
        }
        
        return
    }
    
    let total_dist = abs(x-r) + abs(y-c)
    if total_dist > k || (k - total_dist) % 2 == 1 {
        return "impossible"
    }
    
    DFS(cx: x, cy: y, cur: "", depth: 0)
    
    if answer == "" {
        answer = "impossible"
    }
    
    return answer
}