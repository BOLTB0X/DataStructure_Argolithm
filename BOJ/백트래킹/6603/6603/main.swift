//
//  main.swift
//  6603 로또
//  https://www.acmicpc.net/problem/6603
//  Created by KyungHeon Lee on 2023/08/03.
//

import Foundation

var comArr:[[Int]] = []

while true {
    let inputArr = readLine()!.split(separator: " ").map { Int(String($0))!}
    if inputArr[0] == 0 {
        break
    }
    
    combination(k: inputArr[0], arr: Array(inputArr[1..<inputArr.count]), com: [], cur: 0, depth: 0)
    
    for com in comArr {
        for c in com {
            print(c, terminator: " ")
        }
        print()
    }
    comArr = []
    print()
}

func combination(k:Int, arr:[Int], com: [Int], cur: Int, depth: Int) {
    if 6 == depth {
        comArr.append(com)
        return
    }
    
    for i in cur..<k {
        combination(k: k, arr: arr, com: com + [arr[i]], cur: i+1, depth: depth+1)
    }
    return
}
