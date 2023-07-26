//
//  main.swift
//  11659 구간 합 구하기 4
//  https://www.acmicpc.net/problem/11659
//  Created by KyungHeon Lee on 2023/07/26.
//

import Foundation

let input1 = readLine()!.split { $0 == " " }.map { Int($0)! }
let input2 = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = input1[0]
let M = input1[1]
let arr = input2

var tmp:[Int] = Array(repeating: 0, count: arr.count+1)

for i in 1...arr.count {
    tmp[i] += (tmp[i-1] + arr[i-1])
}

//print(tmp)

for _ in 0..<M {
    let input3 = readLine()!.split { $0 == " "}.map { Int($0)! }
    let i = input3[0]
    let j = input3[1]

    print(tmp[j] - tmp[i-1])
}
