//
//  main.swift
//  1476 날짜 계산
//  https://www.acmicpc.net/problem/1476
//  Created by KyungHeon Lee on 2023/08/03.
//

import Foundation

let inputArr = readLine()!.split(separator: " ").map { Int(String($0))!}
let E = inputArr[0]
let S = inputArr[1]
let M = inputArr[2]
var answer:Int = 1

while true {
    if (answer - E) % 15 == 0 && (answer - S) % 28 == 0 && (answer - M) % 19 == 0 {
        break
    }
    answer += 1
}

print(answer)
