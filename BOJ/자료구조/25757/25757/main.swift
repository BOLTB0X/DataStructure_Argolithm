//
//  main.swift
//  25757 임스와 함께하는 미니게임
//  https://www.acmicpc.net/problem/25757
//  Created by KyungHeon Lee on 2023/08/21.
//

import Foundation

let input1 = readLine()!.components(separatedBy: " ")
var input2:[String] = []

for _ in 0..<Int(input1[0])! {
    input2.append(readLine()!)
}

print(solution(Int(input1[0])!, input1[1], input2))

func solution(_ N: Int, _ G: String, _ playerArr: [String]) -> Int {
    var answer:Int = 0
    let gameDic:[String:Int] = ["Y": 1, "F": 2, "O": 3]
    var playerSet: Set<String> = []
    
    for p in playerArr {
        playerSet.insert(p)
    }
    
    answer = playerSet.count / gameDic[G]!
    return answer
}
