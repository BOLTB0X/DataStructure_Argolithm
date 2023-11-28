// 2020 카카오 인턴십 경주로 건설
// https://school.programmers.co.kr/learn/courses/30/lessons/67259
import Foundation

func BFS(_ board:[[Int]], _ startDir: Int) -> Int {
    let dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]
    let size = board.count
    
    var dist = Array(repeating: Array(repeating: [Int.max, Int.max], count: size), count: size)
    var que: [(x: Int, y: Int, dir: Int)] = []
    var head: Int = 0
    
    dist[0][0] = [0, 0]
    if startDir == 0 { que.append((x: 0, y: 0, dir: 0)) }
    else { que.append((x: 0, y: 0, dir: 1)) }
    
    while head < que.count {
        let cur = que[head]
        head += 1
        
        for i in 0..<4 {
            let nx = cur.x + dir[i][0]
            let ny = cur.y + dir[i][1]
            let nd = i < 2 ? 0 : 1
            
            if nx < 0 || ny < 0 || nx >= size || ny >= size {
                continue
            }
            
            if board[nx][ny] == 1 { continue }
            
            let newCost = nd == cur.dir ? 100 : 600            
            
            if dist[nx][ny][nd] <= dist[cur.x][cur.y][cur.dir] + newCost { continue }
            
            dist[nx][ny][nd] = dist[cur.x][cur.y][cur.dir] + newCost
            que.append((x: nx, y: ny, dir: nd))
        }
    }
    
    return dist[size-1][size-1].min()!
}

func solution(_ board:[[Int]]) -> Int {
    let answer: Int = min(BFS(board, 0), BFS(board, 2))
    return answer
}