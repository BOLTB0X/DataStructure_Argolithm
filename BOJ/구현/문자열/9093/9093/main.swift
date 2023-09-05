//
//  main.swift
//  9093 단어 뒤집기
//  https://www.acmicpc.net/problem/9093
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

let T = Int(readLine()!)!

for _  in 0..<T {
    solution(readLine()!.split(separator: " ").map { String($0)})
}

func solution(_ str: [String]) {
    var answer: [String] = []
    
    for s in str {
        let reversedS = s.map { String($0)}.reversed().joined()
        answer.append(reversedS)
    }
    
    print(answer.joined(separator: " "))
    
    return
}
