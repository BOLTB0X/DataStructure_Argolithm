//
//  main.swift
//  17413 단어 뒤집기 2
//  https://www.acmicpc.net/problem/17413
//  Created by KyungHeon Lee on 2023/09/05.
//

import Foundation

let input = readLine()!

print(solution(input))

func solution(_ str: String) -> String {
    var answer: String = ""
    let str = str.map {String($0)}
    var stack:[String] = []
    var flag:Bool = false
    
    for st in str {
        if flag && st == ">" { // 정방향
            let s = stack.joined()
            answer += ("<"+s+">")
            flag = false
            stack = [] // 비우기
        } else if !flag && st == "<" { // 역방향
            let s = stack.reversed().joined()
            answer += s
            flag = true
            stack = [] // 비우기
        } else if !flag && st == " " {
            let s = stack.reversed().joined()
            answer += s
            answer += " "
            stack = [] // 비우기
        } else {
            stack.append(st)
        }
    }
    
    if !stack.isEmpty {
        let s = stack.map { String($0)}.reversed().joined()
        answer += s
    }
    
    return answer
}
