// https://school.programmers.co.kr/learn/courses/30/lessons/67259
import Foundation

func solution(_ board:[[Int]]) -> Int {
    var answer: Int = 0
    let size = board.count
    var cost = Array(repeating: Array(repeating: [Int.max, Int.max], count: size), count: size)
    
    func inRange(_ x: Int, _ y: Int) -> Bool {
        0 <= x && 0 <= y && x < size && y < size
    }
    
    func BFS(_ x: Int, _ y: Int, _ startDir: Int) {
        var que: [(x: Int, y: Int, d: Int)] = []
        var head: Int = 0
        let dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        
        cost[0][0] = [0, 0]
        que.append((x: x, y: y, d: startDir))
        
        while head < que.count {
            let cur = que[head]
            head += 1
            
            for i in 0..<4 {
                let nx = cur.x + dir[i][0]
                let ny = cur.y + dir[i][1]
                let nd = i < 2 ? 0 : 1
                var addCost = cost[cur.x][cur.y][cur.d] + (cur.d == nd ? 100 : 600)
                
                if !inRange(nx, ny) || board[nx][ny] == 1 { continue }
                
                if cur.x == 0 && cur.y == 0 { addCost = 100 }
                
                if cost[nx][ny][nd] > addCost {
                    cost[nx][ny][nd] = addCost
                    que.append((x: nx, y: ny, d: nd))
                }
            }
        }
        return
    }
    
    BFS(0, 0, 0)
    return min(cost[size-1][size-1][0], cost[size-1][size-1][1])
}