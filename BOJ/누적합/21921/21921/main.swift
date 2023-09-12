//
//  main.swift
//  21921 블로그
//  https://www.acmicpc.net/problem/21921
//  Created by KyungHeon Lee on 2023/09/12.
//

import Foundation

let nx = readLine()!.split(separator: " ").map { Int(String($0))!}
let visited = readLine()!.split(separator: " ").map { Int(String($0))!}
var prefixSum = visited
var answer: Int = 0

for i in 1..<nx[0] {
    prefixSum[i] += prefixSum[i-1]
}

answer = prefixSum[nx[1]-1]
var cnt = 1

for i in 0..<nx[0]-nx[1] {
    let tmp = prefixSum[i+nx[1]] - prefixSum[i]
    
    if answer < tmp {
        answer = tmp
        cnt = 1
    } else if answer == tmp {
        cnt += 1
    }
}

if answer == 0 {
    print("SAD")
} else {
    print(answer)
    print(cnt)
}
