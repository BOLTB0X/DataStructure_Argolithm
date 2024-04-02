//
//  main.swift
//  1158 요세푸스 문제
//  https://www.acmicpc.net/problem/1158
//  Created by KyungHeon Lee on 2023/08/07.
//

import Foundation

func solution(N: Int, K: Int) {
    var que:[Int] = []
    var cnt:Int = K-1
    
    for i in 1...N {
        que.append(i)
    }
    
    print("<", terminator: "")
    while que.count != 1 {
        if cnt >= que.count {
            cnt %= que.count
        }
        
        print("\(String(que.remove(at: cnt))), ",terminator: "")
        cnt += (K-1)
    }
    print("\(que[0])>")
    return
}

let NK = readLine()!.split(separator: " ").map { Int(String($0))! }

solution(N: NK[0], K: NK[1])

