//
//  main.swift
//  10971 외판원 순회 2
//  https://www.acmicpc.net/problem/10971
//  Created by KyungHeon Lee on 2023/09/15.
//

import Foundation

let N = Int(readLine()!)!
var board: [[Int]] = []

for _  in 0..<N {
    board.append(readLine()!.split(separator: " ").map{Int(String($0))! })
}

print(solution(N, board))

func solution(_ N: Int, _ board: [[Int]]) -> Int {
    var answer: Int = Int.max
    var visited = Array(repeating: false, count: N)
    
    func check(_ cur: Int) -> Bool {
        let filterdVis = visited.filter{ $0 == true }
        if filterdVis.count == N && board[cur][0] != 0 {
            return true
        }
        return false
    }
    
    func DFS(_ cur: Int, _ tot: Int, _ depth: Int) {
        if check(cur) {
            answer = min(answer, tot+board[cur][0])
            return
        }
        
        for i in 0..<N {
            if visited[i] || board[cur][i] == 0 {
                continue
            }
            
            visited[i] = true
            DFS(i, tot + board[cur][i], depth+1)
            visited[i] = false
        }
    }
    
    visited[0] = true
    DFS(0, 0, 0)

    return answer
}
