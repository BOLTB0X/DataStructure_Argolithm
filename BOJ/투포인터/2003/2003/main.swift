//
//  main.swift
//  2003 수들의 합 2
//  https://www.acmicpc.net/problem/2003
//  Created by KyungHeon Lee on 2023/08/04.
//

import Foundation

let NM = readLine()!.split(separator: " ").map { Int(String($0))!}
let N = NM[0]
let M = NM[1]
let A = readLine()!.split(separator: " ").map { Int(String($0))!}

var answer:Int = 0

for i in 0..<N {
    var sum:Int = 0
    for j in i..<N {
        sum += A[j]
        if sum == M {
            answer += 1
            break
        }
    }
}

print(answer)
