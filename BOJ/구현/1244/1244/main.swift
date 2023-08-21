//
//  main.swift
//  1244 스위치 켜고 끄기
//  https://www.acmicpc.net/problem/1244
//  Created by KyungHeon Lee on 2023/08/21.
//

import Foundation

let N = Int(readLine()!)!
let inputArr1 = readLine()!.components(separatedBy: " ").map { Int($0)! }
let M = Int(readLine()!)!
var inputArr2: [[Int]] = []

for _ in 0..<M {
    inputArr2.append(readLine()!.components(separatedBy: " ").map { Int($0)! })
}

solution(N, inputArr1, M, inputArr2)

func solution(_ n: Int, _ Swichs: [Int], _ m: Int, _ commend: [[Int]]) {
    var answer:[Int] = Swichs
    
    for cmd in commend {
        if cmd[0] == 1 {
            for i in stride(from: cmd[1]-1, to: n, by: cmd[1]) {
                answer[i] = answer[i] == 1 ? 0 : 1
            }
        } else if cmd[0] == 2 {
            let idx = cmd[1]-1
            answer[idx] = answer[idx] == 1 ? 0 : 1
            
            for i in stride(from: 1, through: n/2, by: 1) {
                if idx+i >= n || idx-i < 0 {
                    break
                }
                
                if answer[idx+i] == answer[idx-i] {
                    answer[idx+i] = answer[idx+i] == 1 ? 0 : 1
                    answer[idx-i] = answer[idx-i] == 1 ? 0 : 1
                } else {
                    break
                }
            }
        }
    }
    
    for i in 0..<answer.count {
        print(answer[i], terminator: " ")
        if (i+1) % 20 == 0 {
            print()
        }
    }
    
    return
}
