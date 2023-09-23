//
//  main.swift
//  10431 줄세우기
//  https://www.acmicpc.net/problem/10431
//  Created by KyungHeon Lee on 2023/08/17.
//

import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    print(input[0], solution(input))
}

func solution(_ children: [Int]) -> Int {
    var answer:Int = 0
    var arr = children
    
    for i in 1...20 {
        for j in stride(from: i+1, through: 20, by: 1) {
            if arr[i] > arr[j] {
                arr.swapAt(i, j)
                answer += 1
            }
        }
    }
    
    return answer
}
