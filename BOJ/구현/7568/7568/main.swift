//
//  main.swift
//  7568 덩치
//  https://www.acmicpc.net/problem/7568
//  Created by KyungHeon Lee on 2023/09/04.
//

import Foundation

let N = Int(readLine()!)!
var input1: [(weights: Int, heights: Int)] = []

for _ in 0..<N {
    let input2 = readLine()!.split(separator: " ").map { Int(String($0))! }
    input1.append((input2[0], input2[1]))
}

func solution(_ N: Int, _ info: [(weights: Int, heights: Int)] ) -> [Int] {
    var answer:[Int] = []
    
    for i in 0..<N {
        var rank:Int = 0
        for j in 0..<N {
            if i == j {
                continue
            }
            
            if info[i].weights < info[j].weights && info[i].heights < info[j].heights {
                rank += 1
            }
        }
        answer.append(rank+1)
    }
    
    
    return answer
}

let ret = solution(N, input1)

for r in ret {
    print(r, terminator: " ")
}

