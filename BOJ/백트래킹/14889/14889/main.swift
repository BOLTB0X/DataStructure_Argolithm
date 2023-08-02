//
//  main.swift
//  14889 스타트와 링크
//  https://www.acmicpc.net/problem/14889
//  Created by KyungHeon Lee on 2023/08/02.
//

import Foundation

let N = Int(readLine()!)!
var board: [[Int]] = []
var visited:[Bool] = Array(repeating: false, count: N)
var answer:Int = 2001

for _ in 0..<N {
    let tmp = readLine()!.split { $0 == " " }.map { Int($0)! }
    board.append(tmp)
}

DFS(0, 0)
print(answer)

func DFS(_ cur: Int, _ depth: Int) {
    if depth == N/2 {
        answer = min(answer, calculateValue())
        return
    }
    
    for i in cur..<N {
        if !visited[i] {
            visited[i] = true
            DFS(i+1,depth+1)
            visited[i] = false
        }
    }
    return
}

func calculateValue() -> Int {
    var startScore:Int = 0
    var linkScore:Int = 0
    
    for i in 0..<N {
        for j in 0..<N {
            if visited[i] && visited[j] {
                startScore += board[i][j]
            } else if !visited[i] && !visited[j] {
                linkScore += board[i][j]
            }
        }
    }
    
    return abs(startScore-linkScore)
}
