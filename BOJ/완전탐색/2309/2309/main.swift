//
//  main.swift
//  2309 일곱 난쟁이
//  https://www.acmicpc.net/problem/2309
//  Created by KyungHeon Lee on 2023/08/03.
//

import Foundation

var arr:[Int] = []
var comArr:[[Int]] = []

for _ in 0..<9 {
    arr.append(Int(readLine()!)!)
}

combination(com: [], r: 7, cur: 0, depth: 0)

for com in comArr {
    let tot = com.reduce(0, +)
    if tot == 100 {
        for c in com.sorted() {
            print(c)
        }
        break
    }
}

func combination(com: [Int], r: Int, cur: Int, depth: Int) {
    if depth == r {
        comArr.append(com)
    }
    
    for i in cur..<9 {
        combination(com: com + [arr[i]], r: r, cur: i+1, depth: depth+1)
    }
}
