//
//  main.swift
//  3085 사탕 게임
//  https://www.acmicpc.net/problem/3085
//  Created by KyungHeon Lee on 2023/08/03.
//

import Foundation

let N = Int(readLine()!)!
var board:[[String]] = []
var answer:Int = 0

for _ in 0..<N {
    let input = readLine()!
    board.append(input.map{String($0)})
}

for i in 0..<board.count {
    for j in 0..<board[0].count-1 {
        if board[i][j] != board[i][j+1] {
            (board[i][j], board[i][j+1]) = (board[i][j+1], board[i][j])
            check()
            (board[i][j], board[i][j+1]) = (board[i][j+1], board[i][j])
        }
    }
}

for i in 0..<board.count {
    for j in 0..<board[0].count-1 {
        if board[j][i] != board[j+1][i] {
            (board[j][i], board[j+1][i]) = (board[j+1][i], board[j][i])
            check()
            (board[j][i], board[j+1][i]) = (board[j+1][i], board[j][i])
        }
    }
}

print(answer)

func check() {
    for i in 0..<board.count {
        var cnt:Int = 1
        for j in 0..<board[0].count-1 {
            if board[i][j] == board[i][j+1] {
                cnt += 1
                answer = max(answer, cnt)
            } else {
                cnt = 1
            }
        }
    }
    
    for i in 0..<board.count {
        var cnt:Int = 1
        for j in 0..<board[0].count-1 {
            if board[j][i] == board[j+1][i] {
                cnt += 1
                answer = max(answer, cnt)
            } else {
                cnt = 1
            }
        }
    }
}
