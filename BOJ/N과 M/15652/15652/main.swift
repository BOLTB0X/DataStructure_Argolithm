//
//  main.swift
//  15652 N과 M (4)
//  https://www.acmicpc.net/problem/15652
//  Created by KyungHeon Lee on 2023/07/27.
//

import Foundation

let inputArr = readLine()!.split { $0 == " " }.map { Int($0)! }

let N = inputArr[0]
let M = inputArr[1]


combination(arr: Array(1...N), N: N, M: M)

func combination(arr: [Int], N: Int, M: Int) {
    var comArr:String = ""
    
    func DFS(com: [Int], cur: Int) {
        if com.count == M {
            comArr += com.map{ String($0) }.joined(separator: " ")
            comArr += "\n"
            return
        }
        
        for i in cur..<arr.count {
            DFS(com: com + [arr[i]], cur: i)
        }
    }
    
    DFS(com: [], cur: 0)
    
    print(comArr)
    
    return
}
