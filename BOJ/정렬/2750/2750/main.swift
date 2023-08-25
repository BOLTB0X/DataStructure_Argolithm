//
//  main.swift
//  2750 수 정렬하기
//  https://www.acmicpc.net/problem/2750
//  Created by KyungHeon Lee on 2023/08/25.
//

import Foundation

let N = Int(readLine()!)!
var arr:[Int] = []

for _ in 0..<N {
    arr.append(Int(readLine()!)!)
}

arr.sort()

for i in 0..<N {
    print(arr[i])
}
