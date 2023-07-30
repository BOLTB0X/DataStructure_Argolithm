//
//  main.swift
//  10819 차이를 최대로
//  https://www.acmicpc.net/problem/10819
//  Created by KyungHeon Lee on 2023/07/30.
//

import Foundation

let N = Int(readLine()!)!
let A = readLine()!.split { $0 == " " }.map { Int($0)! }
var perArr:[[Int]] = []
var answer:Int = -1

func permutation() {
    var visited = [Bool](repeating: false, count: N)
    
    func DFS(per: [Int]) {
        if per.count == N {
            perArr.append(per)
            return
        }
        
        for i in 0..<A.count {
            if !visited[i] {
                visited[i] = true
                DFS(per: per + [A[i]])
                visited[i] = false
            }
        }
    }
    
    DFS(per: [])
    return
}

permutation()

for per in perArr {
    var tot:Int = 0
    for i in 0..<per.count-1 {
        tot += abs(per[i]-per[i+1])
    }
    
    answer = max(tot, answer)
}

print(answer)
