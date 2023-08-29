// https://school.programmers.co.kr/learn/courses/30/lessons/169199
import Foundation

func solution(_ board:[String]) -> Int {
    var answer:Int = -1
    var boardMap: [[String]] = []
    
    func inRange(_ row: Int, _ col: Int, _ cx:Int, _ cy: Int) -> Bool {
        return cx >= 0 && cy >= 0 && cx < row && cy < col
    }
    
    func BFS(_ row: Int, _ col: Int, _ startX: Int, _ startY: Int, _ endX: Int, _ endY: Int) {
        var que:[[Int]] = []
        var dist = Array(repeating: Array(repeating: 0, count: boardMap[0].count), count: boardMap.count)
        
        let dir:[[Int]] = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        
        que.append([startX, startY])
        dist[startX][startY] = 1
        
        while !que.isEmpty {
            let cur = que.removeFirst()
            var cx = cur[0]
            var cy = cur[1]
            
            if cx == endX && cy == endY {
                answer = dist[cx][cy]-1
                break
            }
            
            for d in dir {
                var nx = cx
                var ny = cy
                
                while true {
                    nx += d[0]
                    ny += d[1]
                    
                    if !inRange(row, col, nx, ny) {
                        nx -= d[0]
                        ny -= d[1]
                        break
                    }
                    
                    if boardMap[nx][ny] == "D" {
                        nx -= d[0]
                        ny -= d[1]
                        break
                    }
                }
                
                if dist[nx][ny] == 0 {
                    dist[nx][ny] = dist[cx][cy] + 1
                    que.append([nx,ny])
                }
            }
            
        }
        return
    }
    
    for b in board {
        let splitedB = b.map{String($0)}
        boardMap.append(splitedB)
    }
    
    var start:[Int] = []
    var end:[Int] = []
    
    for i in 0..<boardMap.count {
        for j in 0..<boardMap[0].count {
            if boardMap[i][j] == "R" {
                start.append(i)
                start.append(j)
            } else if boardMap[i][j] == "G" {
                end.append(i)
                end.append(j)
            }
        }
    }
    
    BFS(boardMap.count, boardMap[0].count, start[0], start[1], end[0], end[1])
    
    return answer
}