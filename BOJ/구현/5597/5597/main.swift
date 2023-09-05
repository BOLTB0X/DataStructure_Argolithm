//
//  main.swift
//  5597 과제 안 내신 분..?
//  https://www.acmicpc.net/problem/5597
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

var students: [Int] = Array(repeating: 0, count: 31)

for _ in 0..<28 {
    let input = Int(readLine()!)!
    students[input] = 1
}

for s in 1...30 {
    if students[s] == 0 {
        print(s)
    }
}
