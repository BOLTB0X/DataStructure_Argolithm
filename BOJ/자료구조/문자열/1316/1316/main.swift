//
//  main.swift
//  1316 그룹 단어 체커
//  https://www.acmicpc.net/problem/1316
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

let N = Int(readLine()!)!
var input: [String] = []

for _ in 0..<N {
    input.append(readLine()!)
}

print(solution(N, input))

func solution(_ N: Int, _ strArr: [String]) -> Int{
    var answer: Int = 0
    
    for st in strArr {
        var stack:[Character] = []
        var flag: Bool = true
        
        for s in st {
            if stack.isEmpty {
                stack.append(s)
            } else {
                if !stack.contains(s) || (stack.contains(s) && stack.last! == s) {
                    stack.append(s)
                } else {
                    flag = false
                    break
                }
            }
        }
        
        if flag {
            answer += 1
        }
    }
    
    return answer
}
