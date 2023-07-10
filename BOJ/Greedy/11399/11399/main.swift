//
//  main.swift
//  11399 ATM
//  https://www.acmicpc.net/problem/11399
//  Created by KyungHeon Lee on 2023/07/10.
//

import Foundation

let N = Int(readLine()!)!
var inputArr = readLine()!.split(separator: " ").map { Int(String($0))!}
var answer = 0
var totTime = 0

inputArr = inputArr.sorted()
for i in inputArr {
    totTime += i
    answer += totTime
}
print(answer)
