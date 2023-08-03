//
//  main.swift
//  1748 수 이어 쓰기 1
//  https://www.acmicpc.net/problem/1748
//  Created by KyungHeon Lee on 2023/08/03.
//

import Foundation

let N = Int(readLine()!)!
var answer:Int = 0
var i:Int = 1

while i <= N {
    answer += (N-i+1)
    i *= 10
}

print(answer)
