//
//  main.swift
//  2178 미로 탐색
//  https://www.acmicpc.net/problem/2178
//  Created by KyungHeon Lee on 2023/08/07.
//

import Foundation

func solution(N: Int, M: Int, board: [[Int]]) -> Int {
    var dist:[[Int]] = Array(repeating: Array(repeating: 0, count: M), count: N)
    
    var que:[[Int]] = []
    var dir:[[Int]] = [[1,0],[-1,0],[0,1],[0,-1]]
    que.append([0,0])
    dist[0][0] = 1
    
    while !que.isEmpty {
        let cur = que.removeFirst()
        
        for d in dir {
            let nx = cur[0] + d[0]
            let ny = cur[1] + d[1]
            
            if nx >= 0 && ny >= 0 && nx < N && ny < M {
                if board[nx][ny] == 1 && dist[nx][ny] == 0 {
                    dist[nx][ny] = dist[cur[0]][cur[1]] + 1
                    que.append([nx, ny])
                }
            }
        }
        
    }
    
    return dist[N-1][M-1]
}

let NM = readLine()!.split(separator: " ").map { Int(String($0))! }
var board: [[Int]] = []

for i in 0..<NM[0] {
    board.append(readLine()!.map { Int(String($0))! })
}

let ret = solution(N: NM[0], M: NM[1], board: board)
print(ret)
