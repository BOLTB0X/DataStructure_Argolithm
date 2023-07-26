//
//  main.swift
//  11660 구간 합 구하기 5
//  https://www.acmicpc.net/problem/11660
//  Created by KyungHeon Lee on 2023/07/26.
//

import Foundation

let input1 = readLine()!.split { $0 == " " }.map { Int($0)! }
let N = input1[0]
let M = input1[1]

var board =  [Array(repeating: 0, count: N+1)]

for _ in 1...N {
    let input2 = readLine()!.split { $0 == " " }.map { Int($0)! }
    board.append([0] + input2)
}

// 누적합
var dp = board
for i in 1...N {
    for j in 1...N {
        dp[i][j] = board[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
    }
}

//print(dp)

for _ in 0..<M {
    let input2 = readLine()!.split { $0 == " " }.map { Int($0)! }
    let (x1, y1, x2, y2) = (input2[0], input2[1], input2[2], input2[3])
    
    print(dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1])
}
