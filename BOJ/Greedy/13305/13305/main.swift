//
//  main.swift
//  13305 주유소
//  https://www.acmicpc.net/problem/13305
//  Created by KyungHeon Lee on 2023/09/12.
//

import Foundation

let N = Int(readLine()!)!
let dist = readLine()!.split(separator: " ").map { Int(String($0))!}
let costs = readLine()!.split(separator: " ").map { Int(String($0))!}

var answer: Int = costs[0]*dist[0]
var curCost = costs[0]
var idx:Int = 1

while idx < N-1 {
    if curCost < costs[idx] {
        answer += curCost*dist[idx]
    } else {
        curCost = costs[idx]
        answer += curCost*dist[idx]
    }
    idx += 1
}

print(answer)
