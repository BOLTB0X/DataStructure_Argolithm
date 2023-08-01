//
//  main.swift
//  1759 암호 만들기
//  https://www.acmicpc.net/problem/1759
//  Created by KyungHeon Lee on 2023/08/01.
//

import Foundation

let LC = readLine()!.split { $0 == " " }.map { Int($0)! }
let L = LC[0]
let C = LC[1]

var arr = readLine()!.split { $0 == " " }.map { String($0) }
var comArr:[[String]] = []

arr.sort()
combination(com: [], cur: 0, depth: 0)
// print(comArr)

for com in comArr {
    var mCnt:Int = 0
    var jCnt:Int = 0
    for c in com {
        if ["a", "e", "i", "o", "u"].contains(c) {
            mCnt += 1
        } else {
            jCnt += 1
        }
    }
    
    if mCnt >= 1 && jCnt >= 2 {
        print(com.joined())
    }
}

func combination(com: [String], cur: Int, depth: Int) {
    if depth == L {
        comArr.append(com)
        return
    }
    
    for i in cur..<C {
        combination(com: com + [arr[i]], cur: i+1, depth: depth+1)
    }
    return
}
