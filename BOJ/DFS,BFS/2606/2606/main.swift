//
//  main.swift
//  2606 바이러스
//  https://www.acmicpc.net/problem/2606
//  Created by KyungHeon Lee on 2023/08/07.
//

import Foundation

func solution(N: Int, M: Int, adj: [[Int]]) -> Int {
    var answer: Int = 0
    var visited: [Bool] = Array(repeating: false, count: N+1)
    
    
    func DFS(_ cur: Int) {
        for next in adj[cur] {
            if visited[next] {
                continue
            }
            
            answer += 1
            visited[next] = true
            DFS(next)
        }
    }
    
    visited[1] = true
    DFS(1)
    
    return answer
}

let N = Int(readLine()!)!
let M = Int(readLine()!)!
var adj:[[Int]] = Array(repeating: [], count: N+1)

for _ in 0..<M {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    adj[input[0]].append(input[1])
    adj[input[1]].append(input[0])
}

let ret = solution(N: N, M: M, adj: adj)
print(ret)
