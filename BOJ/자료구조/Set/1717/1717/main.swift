//
//  main.swift
//  1717 집합의 표현
//  https://www.acmicpc.net/problem/1717
//  Created by KyungHeon Lee on 2023/08/08.
//

import Foundation

let nm = readLine()!.split(separator: " ").map {Int(String($0))!}
var nodes:[Int] = Array(repeating: 0, count: nm[0]+1)

for i in 1...nm[0] {
    nodes[i] = i
}

for _ in 0..<nm[1] {
    let cmd = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    if cmd[0] == 0 {
        union(cmd[1], cmd[2])
    } else {
        if find(cmd[1]) == find(cmd[2]) {
            print("YES")
        } else {
            print("NO")
        }
    }
    
}

func find(_ x: Int) -> Int {
    if nodes[x] != x {
        nodes[x] = find(nodes[x])
    }
    return nodes[x]
}

func union(_ x1: Int, _ x2: Int) {
    let x1 = find(x1)
    let x2 = find(x2)
    
    if x1 < x2 {
        nodes[x2] = x1
    } else {
        nodes[x1] = x2
    }
    return
}


