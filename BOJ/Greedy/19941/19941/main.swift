//
//  main.swift
//  19941 햄버거 분배
//  https://www.acmicpc.net/problem/19941
//  Created by KyungHeon Lee on 2023/09/14.
//

import Foundation

let NK = readLine()!.split(separator: " ").map { Int(String($0))! }
let arr = readLine()!.map { String($0) }

func solution(_ N: Int, _ K: Int, _ arr: [String]) -> Int {
    var answer: Int = 0
    var visited = Array(repeating: false, count: N)
    
    func check(_ cur: Int) -> Bool {
        for i in -K...K {
            if i == 0 || cur+i < 0 || cur+i >= N {
                continue
            }
            
            if !visited[cur+i] && arr[cur+i] == "H" {
                visited[cur+i] = true
                return true
            }
        }
        return false
    }
    
    for i in 0..<N {
        if arr[i] == "P" && check(i) { // 사람이면
            answer += 1
        }
    }
    
    return answer
}
print(solution(NK[0], NK[1], arr))
