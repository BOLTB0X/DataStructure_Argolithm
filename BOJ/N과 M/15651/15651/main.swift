//
//  main.swift
//  15651 N과 M (3)
//  https://www.acmicpc.net/problem/15651
//  Created by KyungHeon Lee on 2023/07/27.
//

import Foundation

let inputArr = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = inputArr[0]
let M = inputArr[1]

permutation(arr: Array(1...N), N: N, M: M)

func permutation(arr: [Int], N: Int, M: Int) {
    var perArr = ""
    
    func DFS(per: [Int]) {
        if per.count == M {
            perArr += per.map{ String($0) }.joined(separator: " ")
            perArr += "\n"
            return
        }
        
        for i in 0..<arr.count {
            DFS(per: per + [arr[i]])
        }
    }
    
    DFS(per: [])
    
    print(perArr)
    
    return
}

