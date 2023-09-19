//
//  main.swift
//  1916 최소비용 구하기
//  https://www.acmicpc.net/problem/1916
//  Created by KyungHeon Lee on 2023/09/07.
//

import Foundation

let input1 = Int(readLine()!)!
let input2 = Int(readLine()!)!
var input3: [[Int]] = []

for _ in 0..<input2 {
    input3.append(readLine()!.split(separator: " ").map { Int(String($0))! })
}

let input4 = readLine()!.split(separator: " ").map { Int(String($0))! }

print(solution(input1, input2, input3, input4[0], input4[1]))

func solution(_ N: Int, _ M: Int, _ graphInfo: [[Int]], _ start: Int, _ end: Int) -> Int {
    var answer: Int = 0
    var pq: [(Int, Int)] = []
    var adj: [[(Int, Int)]] = Array(repeating: [(Int, Int)](), count: N+1)
    var dist = Array(repeating: Int.max, count: N+1)
    
    for info in graphInfo {
        adj[info[0]].append((info[1], info[2]))
    }
    
    for i in 1...N {
        adj[i].sort{ $0.1 < $1.1 }
    }
    
    pq.append((start, 0))
    dist[start] = 0
    
    var idx = 0
    
    while idx < pq.count {
        let cur = pq[idx]
        idx += 1
        
        if cur.1 > dist[cur.0] {
            continue
        }
        
        for next in adj[cur.0] {
            let newCost = next.1 + dist[cur.0]
            
            if dist[next.0] > newCost {
                dist[next.0] = newCost
                pq.append((next.0, newCost))
            }
        }
    }
    
    answer = dist[end]
    return answer
}


