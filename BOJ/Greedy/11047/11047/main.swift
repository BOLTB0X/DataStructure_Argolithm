//
//  main.swift
//  11047 동전 0
//  https://www.acmicpc.net/problem/11047
//  Created by KyungHeon Lee on 2023/07/10.
//

import Foundation

let inputArr = readLine()!.split(separator: " ").map { Int(String($0))!}

var N = inputArr[0]
var K = inputArr[1]
var coins: [Int] = []
var answer:Int = 0

for coin in 0..<N {
    let coin = Int(readLine()!)!
    coins.append(coin)
}

for coin in coins.reversed() {
    answer += (K / coin)
    K %= coin
}

print(answer)
