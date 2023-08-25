//
//  main.swift
//  8979 올림픽
//  https://www.acmicpc.net/problem/8979
//  Created by KyungHeon Lee on 2023/08/25.
//

import Foundation

let NK = readLine()!.split(separator: " ").map{ Int(String($0))! }
var medalArr: [[Int]] = []

for _ in 0..<NK[0] {
    medalArr.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
}

print(solution(NK[0], NK[1], medalArr))

func solution(_ N: Int, _ K: Int, _ medals: [[Int]]) -> Int {
    var answer:Int = 0
    var medals = medals
    
    medals.sort {
        if $0[1] != $1[1] {
            return $0[1] > $1[1]
        } else if $0[2] != $1[2] {
            return $0[2] > $1[2]
        } else {
            return $0[3] > $1[3]
        }
    }
    
    var idx = 0
    
    for i in 0..<N {
        if medals[i][0] == K {
            idx = i
            break
        }
    }
    
    for i in 0..<N {
        if medals[idx][1] == medals[i][1] && medals[idx][2] == medals[i][2] && medals[idx][3] == medals[i][3] {
            answer = i + 1
            break
        }
    }
    
    return answer
}
