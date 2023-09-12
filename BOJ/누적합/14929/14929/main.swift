//
//  main.swift
//  14929 귀찮아 (SIB)
//  https://www.acmicpc.net/problem/14929
//  Created by KyungHeon Lee on 2023/09/12.
//

import Foundation

let n = Int(readLine()!)!
let x = readLine()!.split(separator: " ").map { Int(String($0))! }

var prefixSum = Array(repeating: 0, count: n)
var answer = 0

for i in 1..<n {
    prefixSum[i] = (prefixSum[i-1]+x[i-1])
    answer += (x[i]*prefixSum[i])
}

print(answer)
