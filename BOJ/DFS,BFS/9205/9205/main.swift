//
//  main.swift
//  9205 맥주 마시면서 걸어가기
//  https://www.acmicpc.net/problem/9205
//  Created by KyungHeon Lee on 2023/09/08.
//

import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
    let n = Int(readLine()!)!
    let home = readLine()!.split(separator: " ").map { Int(String($0))! }
    var store: [[Int]] = []
    
    for _ in 0..<n {
        store.append(readLine()!.split(separator: " ").map { Int(String($0))! })
    }
    
    let target = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    var answer: String = "sad"
    var que:[[Int]] = [home]
    var idx:Int = 0
    var visited:[Bool] = Array(repeating: false, count: n)
    
    while idx < que.count {
        let cx = que[idx][0]
        let cy = que[idx][1]
        idx += 1
        
        if abs(cx-target[0])+abs(cy-target[1]) <= 1000 {
            answer = "happy"
            break
        }
        
        for i in stride(from: 0, to: n, by: 1) {
            if visited[i] {
                continue
            }
            
            if abs(cx-store[i][0])+abs(cy-store[i][1]) > 1000 {
                continue
            }
            
            visited[i] = true
            que.append([store[i][0], store[i][1]])
            
        }
    }
    
    print(answer)
}

