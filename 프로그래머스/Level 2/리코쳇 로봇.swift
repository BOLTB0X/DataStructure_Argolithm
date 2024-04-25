// https://school.programmers.co.kr/learn/courses/30/lessons/169199
import Foundation

func solution(_ board:[String]) -> Int {
    let board = board.map { Array($0) }
    let pos = findPosition(board)
    
    return BFS(board, pos[0], pos[1])
}

func findPosition(_ board: [[Character]]) -> [(Int, Int)] {
    var ret = [(0, 0), (0, 0)]
    
    for i in board.indices {
        for j in board[i].indices {
            if board[i][j] == "R" {
                ret[0] = (i , j)
            } else if board[i][j] == "G" {
                ret[1] = (i, j)
            }
        }
    }
    
    return ret
}

func inRange(_ x: Int, _ y: Int, _ r: Int, _ c: Int) -> Bool {
    return x >= 0 && y >= 0 && x < r && y < c
}

func BFS(_ board: [[Character]], _ start: (Int, Int), _ end: (Int, Int)) -> Int {
    var ret: Int = -1
    var board: [[Character]] = board
    var que: [(Int, Int)] = [(start.0, start.1)]
    var dist = Array(repeating: Array(repeating: 0, count: board[0].count), count: board.count)
    
    let dx = [-1, 1, 0, 0]
    let dy = [0, 0, -1, 1]
    let row = board.count, col = board[0].count
    
    dist[start.0][start.1] = 1
    
    while !que.isEmpty {
        let cur = que.removeFirst()
        
        if cur.0 == end.0 && cur.1 == end.1 {
            ret = dist[cur.0][cur.1] - 1
            break
        }
        
        for i in 0..<4 {
            var nx = cur.0
            var ny = cur.1
            
            while true {
                nx += dx[i]
                ny += dy[i]
                
                if !inRange(nx, ny, row, col) { 
                    nx -= dx[i]
                    ny -= dy[i]
                    break 
                }
                
                if board[nx][ny] == "D" {
                    nx -= dx[i]
                    ny -= dy[i]
                    break 
                }
            }
            
            if dist[nx][ny] == 0 {
                dist[nx][ny] = dist[cur.0][cur.1] + 1
                que.append((nx, ny))
            }
        }
    }
    
    return ret
}