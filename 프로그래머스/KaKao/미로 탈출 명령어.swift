// 2023 KAKAO BLIND RECRUITMENT 미로 탈출 명령어
// https://school.programmers.co.kr/learn/courses/30/lessons/150365
import Foundation

func solution(_ n:Int, _ m:Int, _ x:Int, _ y:Int, _ r:Int, _ c:Int, _ k:Int) -> String {
    var answer: String = ""
    var board = Array(repeating: Array(repeating: ".", count: m+1), count: n+1)
    let dir:[[Int]] = [[1, 0], [0, -1], [0, 1], [-1, 0]]
    let dirCmd:[String] = ["d", "l", "r", "u"]
    
    func DFS(_ cmd: String, _ cx: Int, _ cy: Int, _ depth: Int) {
        if abs(cx - r) + abs(cy - c) + depth > k || answer != "" {
            return
        }
        
        if depth == k && board[cx][cy] == "E" {
            answer = cmd
            return
        }
        
        for i in 0..<4 {
            let nx = cx + dir[i][0]
            let ny = cy + dir[i][1]
            
            if nx >= 1 && ny >= 1 && nx <= n && ny <= m { 
                DFS(cmd+dirCmd[i], nx, ny, depth+1)
            }
        }
        return
    }
    
    if abs(x-r)+abs(y-c) > k || (k - abs(x-r)+abs(y-c)) % 2 == 1 { 
        answer = "impossible"
    } else {
        board[x][y] = "S"
        board[r][c] = "E"
        DFS("", x, y, 0)
    }
    
    return answer
}