//
//  main.swift
//  2607 비슷한 단어
//  https://www.acmicpc.net/problem/2607
//  Created by KyungHeon Lee on 2023/09/15.
//

import Foundation

let N = Int(readLine()!)!
var vocas:[String] = []

for _ in 0..<N {
    vocas.append(readLine()!)
}

print(solution(N, vocas))

func solution(_ N: Int, _ vocas: [String]) -> Int {
    var answer: Int = 0
    var alpDic: [Character: Int] = [:]
    
    for i in 65..<91 {
        alpDic[Character(UnicodeScalar(i)!)] = 0
    }
    
    for v in vocas[0] {
        alpDic[v]? += 1
    }
    
    for i in 1..<vocas.count {
        var compare = alpDic
        var flag1 = false // 더하거나 빼거나 바꿔여하는 경우
        var flag2 = true
        for v in vocas[i] {
            if compare[v]! > 0 {
                compare[v]? -= 1
            } else {
                if !flag1 {
                    flag1 = true // 한 번은 오케이
                } else {
                    flag2 = false
                    break
                }
            }
        }
        
        if flag2 {
            let tmp = compare.map { $0.value}.reduce(0,+)
            if tmp < 2 {
                //print(vocas[i])
                answer += 1
            }
        }
    }
    return answer
}
