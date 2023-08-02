//
//  main.swift
//  14501 퇴사
//  https://www.acmicpc.net/problem/14501
//  Created by KyungHeon Lee on 2023/08/02.
//

import Foundation

let N = Int(readLine()!)!
var T:[Int] = []
var P:[Int] = []
var answer:Int = -1

for _ in 0..<N {
    let TP = readLine()!.split { $0 == " " }.map { Int($0)! }
    T.append(TP[0])
    P.append(TP[1])
}

DFS(cur: 0, totPay: 0, curPay: 0)
print(answer)

func DFS(cur: Int, totPay: Int, curPay: Int) {
    if cur == N {
        answer = max(answer, totPay)
        return
    } else if cur > N {
        answer = max(answer, totPay - curPay)
        return
    }
    
    for i in cur..<N {
        DFS(cur: i+T[i], totPay: totPay+P[i], curPay: P[i])
    }
    return
}
