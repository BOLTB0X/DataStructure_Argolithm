//
//  main.swift
//  15649 N과 M (1)
//  https://www.acmicpc.net/problem/15649
//  Created by KyungHeon Lee on 2023/07/27.
//

import Foundation

let inputArr = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = inputArr[0]
let M = inputArr[1]

permutation(arr: Array(1...N), N: N, M: M)

func permutation(arr: [Int], N: Int, M: Int) {
    var perArr: [[Int]] = []
    var visited = [Bool](repeating: false, count: N)
    
    func DFS(per: [Int]) {
        if per.count == M {
            perArr.append(per)
            return
        }
        
        for i in 0..<arr.count {
            if !visited[i] {
                visited[i] = true
                DFS(per: per + [arr[i]])
                visited[i] = false
            }
        }
    }
    
    DFS(per: [])
    
    for per in perArr {
        for p in per {
            print(p, terminator: " ")
        }
        print()
    }
    
    return
}

