//
//  main.swift
//  2164 카드 2
//  https://www.acmicpc.net/problem/2164
//  Created by KyungHeon Lee on 2023/09/11.
//

import Foundation

let N = Int(readLine()!)!

var que = Array(1...N)
var qIdx: Int = 0

if N == 1 {
    print(1)
} else {
    
    while true {
        que[qIdx] = 0
        que.append(que[qIdx+1])
        que[qIdx+1] = 0
        
        if que[que.count-2] == 0 {
            print(que.last!)
            break
        }
        qIdx += 2
    }
}
