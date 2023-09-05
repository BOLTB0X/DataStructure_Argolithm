//
//  main.swift
//  87694 아이템 줍기
//  https://school.programmers.co.kr/learn/courses/30/lessons/87694
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

func solution(_ rectangle: [[Int]], _ characterX: Int, _ characterY: Int, _ itemX: Int, _ itemY: Int) -> Int {
    var answer:Int = 0
    var board: [[Int]] = Array(repeating: Array(repeating: -1, count: 102), count: 102)
    
    func BFS(_ sx: Int, _ sy: Int, _ tx: Int, _ ty: Int) -> Int {
        var ret:Int = 0
        var dist = Array(repeating: Array(repeating: 0, count: 102), count: 102)
        var que:[[Int]] = []
        var qIdx: Int = 0
        
        let dir:[[Int]] = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        
        que.append([sx, sy])
        dist[sx][sy] = 1
        
        while qIdx < que.count {
            let cur = que[qIdx]
            qIdx += 1
            
            if cur[0] == tx && cur[1] == ty {
                ret = dist[tx][ty] / 2
                break
            }
            
            for d in dir {
                let nx = cur[0] + d[0]
                let ny = cur[1] + d[1]
                
                if nx < 0 || ny < 0 || nx >= 102 || ny >= 102 {
                    continue
                }
                
                if dist[nx][ny] > 0 || board[nx][ny] != 1 {
                    continue
                }
                
                que.append([nx, ny])
                dist[nx][ny] = dist[cur[0]][cur[1]] + 1
            }
        }
        
        return ret
    }
    
    for rect in rectangle {
        let newRect = rect.map { $0*2 }
        
        for i in newRect[0]...newRect[2] {
            for j in newRect[1]...newRect[3] {
                if newRect[0] < i && newRect[2] > i && newRect[1] < j && newRect[3] > j {
                    board[i][j] = 0
                } else if board[i][j] != 0 {
                    board[i][j] = 1
                }
            }
        }
    }
    
    answer = BFS(characterX*2, characterY*2, itemX*2, itemY*2)
    
    return answer
}

print(solution([[1,1,7,4],[3,2,5,5],[4,3,6,9],[2,6,8,8]], 1, 3, 7, 8)) // 17
print(solution([[1,1,8,4],[2,2,4,9],[3,6,9,8],[6,3,7,7]], 9, 7, 6, 1)) // 11
print(solution([[1,1,5,7]], 1, 1, 4, 7)) //9
print(solution([[2,1,7,5],[6,4,10,10]], 3, 1, 7, 10)) // 15
print(solution([[2,2,5,5],[1,3,6,4],[3,1,4,6]], 1, 4, 6, 3)) // 10

