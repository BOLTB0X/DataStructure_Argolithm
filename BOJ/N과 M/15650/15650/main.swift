//
//  main.swift
//  15650 N과 M (2)
//  https://www.acmicpc.net/problem/15650
//  Created by KyungHeon Lee on 2023/07/27.
//

import Foundation

let inputArr = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = inputArr[0]
let M = inputArr[1]

combination(arr: Array(1...N), N: N, M: M)

func combination(arr: [Int], N: Int, M: Int) {
    var comArr: [[Int]] = []
    
    func DFS(com: [Int], cur: Int) {
        if com.count == M {
            comArr.append(com)
            return
        }
        
        for i in cur..<arr.count {
            DFS(com: com + [arr[i]], cur: i+1)
        }
    }
    
    DFS(com: [], cur: 0)
    
    for com in comArr {
        for c in com {
            print(c, terminator: " ")
        }
        print()
    }
    
    return
}
