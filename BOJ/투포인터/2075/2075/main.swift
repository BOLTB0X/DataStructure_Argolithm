//
//  main.swift
//  2075 N번째 큰 수
//  https://www.acmicpc.net/problem/2075
//  Created by KyungHeon Lee on 2023/08/04.
//

import Foundation

let N = Int(readLine()!)!
var A:[Int] = []

for _ in 0..<N {
    A += readLine()!.split(separator: " ").map { Int(String($0))!}
    A = Array(A.sorted(by: >)[0..<N])
}

print(A[N-1])
