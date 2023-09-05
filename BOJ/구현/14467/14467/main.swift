//
//  main.swift
//  14467 소가 길을 건너간 이유 1
//  https://www.acmicpc.net/problem/14467
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

let N = Int(readLine()!)!
var cows: [Int] = Array(repeating: -1, count: 11)
var answer:Int = 0

for _ in 0..<N {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    var flag:Bool = false
    
    if cows[input[0]] != -1 && cows[input[0]] != input[1] {
        flag = true
        cows[input[0]] = input[1]
    } else if cows[input[0]] == -1 {
        cows[input[0]] = input[1]
    }
    
    if flag {
        //print(input[0], input[1])
        answer += 1
    }
}

print(answer)
