//
//  main.swift
//  14500 테트로미노
//  https://www.acmicpc.net/problem/14500
//  Created by KyungHeon Lee on 2023/08/09.
//

import Foundation

let NM = readLine()!.split(separator: " ").map { Int(String($0))! }
var board:[[Int]] = []

for _ in 0..<NM[0] {
    board.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

print(solution(N: NM[0], M: NM[1], board: board))

func solution(N: Int, M: Int, board: [[Int]]) -> Int {
    var answer:Int  = 0
    var visited:[[Bool]] = Array(repeating: Array(repeating: false, count: M), count: N)
    let dir = [[1,0], [-1,0], [0,-1], [0,1]]
    
    for i in 0..<N {
        for j in 0..<M {
            specialShape(i, j)
            
            visited[i][j] = true
            DFS(i,j, board[i][j], 0)
            visited[i][j] = false
        }
    }
    
    func DFS(_ x: Int, _ y: Int, _ tot: Int, _ depth: Int) {
        if depth == 3 {
            answer = max(answer, tot)
            return
        }
        
        for d in dir {
            let nx = x + d[0]
            let ny = y + d[1]
            
            if nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] {
                visited[nx][ny] = true
                DFS(nx, ny, tot+board[nx][ny], depth+1)
                visited[nx][ny] = false
            }
        }
        return
    }
    
    func specialShape(_ x: Int, _ y: Int) {
        for i in 0..<4 {
            var tot = board[x][y]
            for j in 0..<3 {
                let k = (i+j)%4
                let nx = x + dir[k][0]
                let ny = y + dir[k][1]
                
                if nx < 0 || ny < 0 || nx >= N || ny >= M {
                    continue
                }
                tot += board[nx][ny]
            }
            answer = max(answer, tot)
        }
        
        return
    }
    
    return answer
}
