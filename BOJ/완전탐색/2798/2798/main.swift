//
//  main.swift
//  2798 블랙잭
//  https://www.acmicpc.net/problem/2798
//  Created by KyungHeon Lee on 2023/09/04.
//

import Foundation

let input1 = readLine()!.split(separator: " ").map { Int(String($0))!}
let input2 = readLine()!.split(separator: " ").map { Int(String($0))!}

print(solution(input1[0], input1[1], input2))

func solution(_ N: Int, _ M: Int, _ cards:[Int]) -> Int {
    var answer:Int = 0
    
    for i in 0..<N-2 {
        for j in i+1..<N-1 {
            for k in j+1..<N {
                if cards[i]+cards[j]+cards[k] <= M {
                    answer = max(cards[i]+cards[j]+cards[k], answer)
                }
            }
        }
    }
    
    return answer
}
