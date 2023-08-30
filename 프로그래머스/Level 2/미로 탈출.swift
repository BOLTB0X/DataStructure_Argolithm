// https://school.programmers.co.kr/learn/courses/30/lessons/159993
import Foundation

func solution(_ maps:[String]) -> Int {
    var answer:Int = -1
    var board:[[String]] = []
    let row = maps.count
    let col = maps[0].count
    
    func inRange(_ x: Int, _ y: Int) -> Bool {
        return x >= 0 && y >= 0 && x < row && y < col
    }
    
    func BFS(_ sx: Int, _ sy: Int, _ ex: Int, _ ey: Int) -> Int {
        var res:Int = 0
        var dist:[[Int]] = Array(repeating: Array(repeating: 0, count: maps[0].count), count: maps.count)
        var que:[[Int]] = []
        let dir:[[Int]] = [[1,0],[-1,0],[0,1],[0,-1]]
        
        dist[sx][sy] = 1
        que.append([sx, sy])
        
        while !que.isEmpty {
            let cur = que.removeFirst()
            
            if ex == cur[0] && ey == cur[1] {
                res = dist[ex][ey]-1
                break
            }
            
            for d in dir {
                let nx = cur[0] + d[0]
                let ny = cur[1] + d[1]
                
                if !inRange(nx, ny) || board[nx][ny] == "X" {
                    continue
                }
                
                if dist[nx][ny] != 0 {
                    continue
                }
                
                dist[nx][ny] = dist[cur[0]][cur[1]] + 1
                que.append([nx, ny])
            }
        }
        return res
    }
    
    for m in maps {
        let splitedM = m.map { String($0) }
        board.append(splitedM)
    }
    
    var start:[Int] = []
    var lever:[Int] = []
    var end:[Int] = []
    
    for i in 0..<row {
        for j in 0..<col {
            if board[i][j] == "S" {
                start.append(i)
                start.append(j)
            } else if board[i][j] == "L" {
                lever.append(i)
                lever.append(j)
            } else if board[i][j] == "E" {
                end.append(i)
                end.append(j)
            } 
        }
    }
    
    answer = BFS(start[0], start[1], lever[0], lever[1])
    if answer == 0 {
        return -1
    } else {
        let res = BFS(lever[0], lever[1], end[0], end[1])
        if res == 0 {
            return -1
        } else {
            answer += res
        }
    }
    
    return answer
}