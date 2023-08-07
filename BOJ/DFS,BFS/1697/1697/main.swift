//
//  main.swift
//  1697 숨바꼭질
//  https://www.acmicpc.net/problem/1697
//  Created by KyungHeon Lee on 2023/08/07.
//

import Foundation

func solution(N: Int, K: Int) -> Int {
    var answer:Int = 0
    var visited: [Bool] = Array(repeating: false, count: 100001)
    var que:[[Int]] = [] // 위치, 시간
    que.append([N, 0])
    visited[N] = true
    
    while !que.isEmpty {
        let cur = que.removeFirst()
        
        if cur[0] == K {
            answer = cur[1]
            break
        }
        
        if cur[0]+1 < 100001 && !visited[cur[0]+1] {
            visited[cur[0]+1] = true
            que.append([cur[0]+1, cur[1]+1])
        }
        
        if cur[0]-1 >= 0 && !visited[cur[0]-1] {
            visited[cur[0]-1] = true
            que.append([cur[0]-1, cur[1]+1])
        }
        
        if cur[0]*2 < 100001 && !visited[cur[0]*2] {
            visited[cur[0]*2] = true
            que.append([cur[0]*2, cur[1]+1])
        }
    }
    
    return answer
}

let NK = readLine()!.split(separator: " ").map { Int(String($0))! }

let ret = solution(N: NK[0], K: NK[1])
print(ret)
