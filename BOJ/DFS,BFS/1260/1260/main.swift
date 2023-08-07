//
//  main.swift
//  1260 DFS와 BFS
//  https://www.acmicpc.net/problem/1260
//  Created by KyungHeon Lee on 2023/08/07.
//

import Foundation

func solution(N: Int, M: Int, V: Int, adj: [[Int]]) {
    var adj = adj
    var visited: [Bool] = Array(repeating: false, count: N+1)
    
    func DFS(_ cur: Int) {
        print(cur, terminator: " ")
        visited[cur] = true
        
        for next in adj[cur] {
            if visited[next] {
                continue
            }
            
            DFS(next)
        }
        return
    }
    
    func BFS(_ start: Int) {
        var que:[Int] = []
        
        que.append(start)
        visited[start] = true
        
        
        while !que.isEmpty {
            let cur = que.removeFirst()
            print(cur, terminator: " ")
            
            for next in adj[cur] {
                if visited[next] {
                    continue
                }
                
                visited[next] = true
                que.append(next)
            }
        }
        return
    }
    
    for i in 1...N {
        adj[i].sort()
    }
    
    DFS(V)
    print()
    
    for i in 0...N {
        visited[i] = false
    }
    
    BFS(V)
    print()
    return
}

let NMV = readLine()!.split(separator: " ").map { Int(String($0))! }
var adjList:[[Int]] = Array(repeating: [], count: NMV[0]+1)

for _ in 0..<NMV[1] {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    adjList[input[0]].append(input[1])
    adjList[input[1]].append(input[0])
}

solution(N: NMV[0], M: NMV[1], V: NMV[2], adj: adjList)

