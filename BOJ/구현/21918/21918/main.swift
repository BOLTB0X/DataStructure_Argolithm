//
//  main.swift
//  21918 전구
//  https://www.acmicpc.net/problem/21918
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

let input1 = readLine()!.split(separator: " ").map{ Int(String($0))! }
let input2 = readLine()!.split(separator: " ").map{ Int(String($0))! }
var input3:[[Int]] = []

for _ in 0..<input1[1] {
    input3.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

let ret = solution(input1[0], input1[1], input2, input3)

for r in ret {
    print(r, terminator: " ")
}
exit(0)

func solution(_ N: Int, _ M: Int, _ states:[Int], _ cmds: [[Int]]) -> [Int] {
    var answer:[Int] = states
    
    for cmd in cmds {
        if cmd[0] == 1 {
            answer[cmd[1]-1] = cmd[2]
        } else if cmd[0] == 2 {
            for i in cmd[1]-1..<cmd[2] {
                answer[i] = answer[i] == 1 ? 0 : 1
            }
            
        } else if cmd[0] == 3 {
            for i in cmd[1]-1..<cmd[2] {
                answer[i] = 0
            }
        } else {
            for i in cmd[1]-1..<cmd[2] {
                answer[i] = 1
            }
        }
    }
    
    return answer
}
