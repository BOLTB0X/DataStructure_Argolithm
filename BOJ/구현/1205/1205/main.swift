//
//  main.swift
//  1205 등수 구하기
//  https://www.acmicpc.net/problem/1205
//  Created by KyungHeon Lee on 2023/09/04.
//

import Foundation

func solution(_ N: Int, _ newSocre: Int, _ P: Int, _ AllSocre: [Int]) -> Int {
    var answer:Int = 0
    
    if AllSocre.last! >= newSocre && N == P {
        answer = -1
    } else {
        for i in 0..<AllSocre.count {
            if newSocre < AllSocre[i] {
                answer += 1
            }
        }
        
        answer += 1
    }
    
    return answer
}

let input1 = readLine()!.split(separator: " ").map { Int(String($0))! }

if input1[0] != 0 {
    let input2 = readLine()!.split(separator: " ").map { Int(String($0))! }
    print(solution(input1[0], input1[1], input1[2], input2))
} else {
    print(1)
}
exit(0)
