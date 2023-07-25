//
//  main.swift
//  1068 트리
//  https://www.acmicpc.net/problem/1068
//  Created by KyungHeon Lee on 2023/07/25.
//

import Foundation

let N = Int(readLine()!)!
let inputArr = readLine()!.split { $0 == " " }.map { Int($0)! }
let target = Int(readLine()!)!

var answer:Int = 0
var graph:[[Int]] = Array(repeating: [], count: N)
var root:Int = 0

for i in 0..<N {
    if inputArr[i] == -1 {
        root = i
        continue
    }
    graph[inputArr[i]].append(i)
}

if inputArr[target] == -1 {
    print(0)
} else {
    graph[inputArr[target]].removeAll{$0 == target}
    DFS(root)
    
    print(answer)
}

func DFS(_ cur: Int) {
    if graph[cur].count == 0 {
        answer += 1
    }
    
    for next in graph[cur] {
        DFS(next)
    }
}
