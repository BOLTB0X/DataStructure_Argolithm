//
//  main.swift
//  2292 벌집
//  https://www.acmicpc.net/problem/2292
//  Created by KyungHeon Lee on 2023/08/14.
//

import Foundation

let N = Int(readLine()!)!
var answer:Int = 1
var number:Int = 1

while N > number {
    number += (answer * 6)
    answer += 1
}

print(answer)
