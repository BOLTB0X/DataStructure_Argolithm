//
//  main.swift
//  11403 경로 찾기
//  https://www.acmicpc.net/problem/11403
//  Created by KyungHeon Lee on 2023/09/07.
//

import Foundation

let input1 = Int(readLine()!)!
var input2: [[Int]] = []

for _ in 0..<input1 {
    input2.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

solution(input1, input2)

func solution(_ N: Int, _ adj:[[Int]])  {
    var answer: [[Int]] = adj
    
    for k in 0..<N {
        for a in 0..<N {
            for b in 0..<N {
                if answer[a][k] == 1 && answer[k][b] == 1 {
                    answer[a][b] = 1
                }
            }
        }
    }
    
    for a in answer {
        for i in 0..<N {
            print(a[i], terminator: " ")
        }
        print()
    }
    
    return
}
