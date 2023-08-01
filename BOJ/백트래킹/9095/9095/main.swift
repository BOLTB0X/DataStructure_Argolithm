//
//  main.swift
//  9095 1, 2, 3 더하기
//  https://www.acmicpc.net/problem/9095
//  Created by KyungHeon Lee on 2023/08/01.
//

import Foundation

let T = Int(readLine()!)!
var answer:Int = 0

func DFS(_ n: Int , _ totalValue: Int) {
    if totalValue > n {
        return
    }
    
    if totalValue == n {
        answer += 1
        return
    }
    
    for i in 1...3 {
        DFS(n, totalValue + i)
    }
    return
}

for _ in 0..<T {
    let n = Int(readLine()!)!
    DFS(n, 0)
    print(answer)
    answer = 0
}
