//
//  main.swift
//  1037 약수
//  https://www.acmicpc.net/problem/1037
//  Created by KyungHeon Lee on 2023/07/06.
//

import Foundation

let N = Int(readLine()!)!
let inputArr = readLine()!.split(separator: " ").map { Int(String($0))!}

var maxValue = inputArr[0]
var minValue = inputArr[0]

for i in 1..<N {
    maxValue = max(maxValue, inputArr[i])
    minValue = min(minValue, inputArr[i])
}

print("\(maxValue*minValue)")
