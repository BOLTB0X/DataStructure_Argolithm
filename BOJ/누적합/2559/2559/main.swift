//
//  main.swift
//  2559 수열
//  https://www.acmicpc.net/problem/2559
//  Created by KyungHeon Lee on 2023/07/26.
//

import Foundation

let input1 = readLine()!.split { $0 == " " }.map { Int($0)! }
let input2 = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = input1[0]
let K = input1[1]
let arr = input2

var answer:Int = -1
var tmp = arr

for i in 1..<arr.count {
    tmp[i] += tmp[i-1]
}
//print(tmp)
answer = tmp[K-1]

for i in 0..<arr.count-K {
    answer = max(answer, tmp[i+K] - tmp[i])
    //print(i, answer, tmp[i+K], tmp[i])
}

print(answer)
