//
//  main.swift
//  1976 여행 가자
//  https://www.acmicpc.net/problem/1976
//  Created by KyungHeon Lee on 2023/09/08.
//

import Foundation

let N = Int(readLine()!)!
let M = Int(readLine()!)!
var cities:[[Int]] = []

for _ in 0..<N {
    cities.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

let plans = readLine()!.split(separator: " ").map { Int(String($0))! }

var answer:String = "YES"
var nodes: [Int] = [Int](0...N)
var visited: [Bool] = Array(repeating: false, count: N+1)

func find(_ x: Int) -> Int {
    if nodes[x] != x {
        nodes[x] = find(nodes[x])
    }
    
    return nodes[x]
}

func union(_ a: Int, _ b: Int) {
    let a = find(a)
    let b = find(b)
    
    if a == b {
        return
    }
    
    if a < b {
        nodes[b] = a
    } else {
        nodes[a] = b
    }
    
    return
}

func DFS(_ cur: Int) {
    visited[cur] = true
    
    for i in 0..<N {
        if cities[cur-1][i] == 1 && !visited[i+1]{
            DFS(i+1)
        }
    }
}

//for i in 0..<N {
//    for j in 0..<N {
//        if cities[i][j] == 1 {
//            //union(i+1, j+1)
//            //adj[i+1].append(j+1)
//        }
//    }
//}

//Set(plans.map { find($0) }).count == 1 ? print("YES") : print("NO")

DFS(plans.first!)

var flag = 1

for p in plans {
    if !visited[p] {
        flag = 0
        break
    }
}

flag == 1 ? print("YES") : print("NO")
