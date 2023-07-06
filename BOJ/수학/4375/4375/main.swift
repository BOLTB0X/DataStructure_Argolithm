//
//  main.swift
//  4375 1
//  https://www.acmicpc.net/problem/4375
//  Created by KyungHeon Lee on 2023/07/06.
//

import Foundation

while let n = readLine() {
    var answer = 0
    var num = 1
    
    while true {
        answer += 1
        
        if (num % Int(n)!) == 0 {
            print("\(answer)")
            break
        } else {
            num = (num * 10) + 1
            num %= Int(n)!
        }
    }
}

