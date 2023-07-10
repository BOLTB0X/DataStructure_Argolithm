//
//  main.swift
//  1931 회의실 배정
//  https://www.acmicpc.net/problem/1931
//  Created by KyungHeon Lee on 2023/07/10.
//

import Foundation

let N = Int(readLine()!)!
var roomArr: [[Int]] = []
var answer:Int = 0

for _ in 0..<N {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    roomArr.append([input[0], input[1]])
}

// 정렬 조건 변경
roomArr = roomArr.sorted{ a, b -> Bool in
    if a[1] == b[1] {
        return a[0] < b[0]
    } else {
        return a[1] < b[1]
    }
}

var cmp: Int = roomArr[0][1]
answer += 1

for i in 1..<roomArr.count {
    if cmp <= roomArr[i][0] {
        answer += 1
        cmp = roomArr[i][1]
    }
}

print(answer)
