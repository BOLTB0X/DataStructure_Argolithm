//
//  main.swift
//  4963 섬의 개수
//  https://www.acmicpc.net/problem/4963
//  Created by KyungHeon Lee on 2023/08/07.
//

import Foundation

func solution(w: Int, h: Int, board:[[Int]]) -> Int {
    var answer:Int = 0
    var visited:[[Bool]] = Array(repeating: Array(repeating: false, count: w), count: h)
    
    var dir:[[Int]] = [[1,0],[-1,0],[0,1],[0,-1],[1,-1],[-1,1],[-1,-1],[1,1]]
    
    func DFS(_ x: Int, _ y: Int) {
        visited[x][y] = true
        
        for d in dir {
            let nx = x + d[0]
            let ny = y + d[1]
            
            if nx < 0 || ny < 0 || nx >= h || ny >= w {
                continue
            }
            
            if visited[nx][ny] {
                continue
            }
            
            if board[nx][ny] == 0 {
                continue
            }
            
            DFS(nx, ny)
        }
        return
    }
    
    for i in 0..<h {
        for j in 0..<w {
            if board[i][j] == 1 && !visited[i][j] {
                answer += 1
                DFS(i, j)
            }
        }
    }
    
    return answer
}

while true {
    let wh = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    if wh[0] == 0 && wh[1] == 0 {
        break
    }
    
    var board:[[Int]] = []
    
    for _ in 0..<wh[1] {
        board.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
    }
    
    let ret = solution(w: wh[0], h: wh[1], board: board)
    print(ret)
}

