//
//  main.swift
//  9012 괄호
//  https://www.acmicpc.net/problem/9012
//  Created by KyungHeon Lee on 2023/08/07.
//

import Foundation

func solution(_ VP: [String]) {
    var cnt:Int = 0
    
    for v in VP {
        if v == "(" {
            cnt += 1
        } else {
            if cnt <= 0 {
                print("NO")
                return
            }
            cnt -= 1
        }
    }
    
    if cnt > 0 {
        print("NO")
    } else {
        print("YES")
    }
    return
}

let T = Int(readLine()!)!

for _ in 0..<T {
    let input = readLine()!.map{ String($0)}
    solution(input)
}
