//
//  main.swift
//  4396 지뢰 찾기
//  https://www.acmicpc.net/problem/4396
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

let N = Int(readLine()!)!
var input1:[[String]] = []
var input2:[[String]] = []

for _ in 0..<N {
    input1.append(readLine()!.map{String($0)})
}

for _ in 0..<N {
    input2.append(readLine()!.map{String($0)})
}

solution(N, input1, input2)

func solution(_ N: Int, _ gameBoard: [[String]], _ openBoard: [[String]]) {
    var answer = openBoard
    var flag: Bool = false
    
    func updateBoard() {
        for i in 0..<N {
            for j in 0..<N {
                if gameBoard[i][j] == "*" {
                    answer[i][j] = "*"
                }
            }
        }
        return
    }
    
    func getCount(_ i: Int, _ j: Int) -> Int {
        var cnt: Int = 0
        
        if i + 1 < N && gameBoard[i+1][j] == "*" {
            cnt += 1
        }
        
        if j + 1 < N && gameBoard[i][j+1] == "*" {
            cnt += 1
        }
        
        if i - 1 >= 0 && gameBoard[i-1][j] == "*" {
            cnt += 1
        }
        
        if j - 1 >= 0 && gameBoard[i][j-1] == "*" {
            cnt += 1
        }
        
        if i+1 < N && j+1<N && gameBoard[i+1][j+1] == "*" {
            cnt += 1
        }
        
        if i-1 >= 0 && j-1 >= 0 && gameBoard[i-1][j-1] == "*" {
            cnt += 1
        }
        
        if i-1 >= 0 && j+1 < N && gameBoard[i-1][j+1] == "*" {
            cnt += 1
        }
        
        if i+1 < N && j-1 >= 0 && gameBoard[i+1][j-1] == "*" {
            cnt += 1
        }
        
        return cnt
    }
    
    for i in 0..<N {
        for j in 0..<N {
            if answer[i][j] == "x" {
                if gameBoard[i][j] == "*" {
                    answer[i][j] = "*"
                    flag = true
                } else {
                    answer[i][j] = "\(getCount(i, j))"
                }
            }
        }
    }
    
    if flag {
        updateBoard()
    }
    
    for ans in answer {
        print(ans.joined())
    }
    return
}
