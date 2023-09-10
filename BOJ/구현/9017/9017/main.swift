//
//  main.swift
//  9017 크로스 컨트리
//  https://www.acmicpc.net/problem/9017
//  Created by KyungHeon Lee on 2023/09/10.
//

import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
    let N = Int(readLine()!)!
    let teams = readLine()!.split(separator: " ").map { Int(String($0))! }
    
    var answer:Int = 0
    var finalDic: [Int: (cnt: Int, totalScore: Int, fouthPlayer: Int)] = [:]
    var teamInfo: [Int: Int] = [:]
    
    for i in 0..<N {
        if let _ = teamInfo[teams[i]] {
            teamInfo[teams[i]]? += 1

        } else {
            teamInfo[teams[i]] = 1
        }
    }
    
    let newTeam = teamInfo.filter { $0.value == 6 }
    
    //print(newTeam)
    
    var rank: Int = 1
    for i in 0..<N {
        if let _ = newTeam[teams[i]] {
            if let value = finalDic[teams[i]] {
                if value.cnt < 4 {
                    finalDic[teams[i]] = (value.cnt+1, value.totalScore+rank, 0)
                } else if value.cnt == 4 {
                    finalDic[teams[i]] = (value.cnt+1, value.totalScore, rank)
                }
            } else {
                finalDic[teams[i]] = (1, rank, 0)
            }
            rank += 1
        }
    }
    
    
    var maxValue = (Int.max, Int.max)
    for (key, value) in finalDic {
        if value.totalScore < maxValue.0 {
            maxValue.0 = value.totalScore
            maxValue.1 = value.fouthPlayer
            answer = key
        } else if value.totalScore == maxValue.0 && value.fouthPlayer < maxValue.1 {
            maxValue.1 = value.fouthPlayer
            answer = key
        }
    }
    
    print(answer)
}
