// 2023 KAKAO BLIND RECRUITMENT 미로 탈출 명령어
import Foundation

func solution(_ n:Int, _ m:Int, _ x:Int, _ y:Int, _ r:Int, _ c:Int, _ k:Int) -> String {
    var answer:String = ""
    var board:[[String]] = Array(repeating: Array(repeating: ".", count: m+1), count: n+1)
    let dir:[[Int]] = [[1, 0], [0, -1], [0, 1], [-1, 0]]
    let dirCmd:[String] = ["d", "l", "r", "u"]
    
    func DFS(cx: Int, cy: Int, cur: String, depth: Int) {
        if depth + abs(cx-r)+abs(cy-c) > k || answer != "" {
            return
        }
        
        if depth == k && board[cx][cy] == "E" {
            answer = cur
            return
        }
        
        for i in 0..<4 {
            let nx = cx + dir[i][0]
            let ny = cy + dir[i][1]
            
            if nx >= 1 && ny >= 1 && nx <= n && ny <= m {
                DFS(cx: nx, cy: ny, cur: cur + dirCmd[i], depth: depth+1)
            }
        }
        return
    }
    
    if abs(x-r)+abs(y-c) > k || (k-abs(x-r)+abs(y-c)) % 2 == 1 {
        answer = "impossible"
    } else {
        board[x][y] = "S"
        board[r][c] = "E"
        
        DFS(cx: x, cy: y, cur: "", depth: 0)
    }
        
    return answer
}