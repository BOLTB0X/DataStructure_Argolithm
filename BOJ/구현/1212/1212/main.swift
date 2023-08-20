//
//  main.swift
//  1212 8진수 2진수
//  https://www.acmicpc.net/problem/1212
//  Created by KyungHeon Lee on 2023/08/20.
//

import Foundation


let inputStr = readLine()!

print(solution(inputStr))

func solution(_ oct: String) -> String {
    var answer:String = ""
    let oct = oct.map { String($0) }
    
    for i in 0..<oct.count {
        var num = Int(oct[i])!
        var tmp = ""
        
        if num == 0 {
            tmp += "0"
        } else {
            while num != 1 {
                tmp += String(num%2)
                num /= 2
            }
            tmp += "1"
        }
        
        if i > 0 && tmp.count == 1 {
            tmp += "00"
        } else if i > 0 && tmp.count == 2 {
            tmp += "0"
        }
        
        answer += String(tmp.reversed())
    }
    
    return answer
}
