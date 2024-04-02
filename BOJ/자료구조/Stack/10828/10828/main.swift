//
//  main.swift
//  10828 스택
//  https://www.acmicpc.net/problem/10828
//  Created by KyungHeon Lee on 2023/08/08.
//

import Foundation

let N = Int(readLine()!)
var stack: [Int] = []

for _ in 0..<N! {
    let input = readLine()!.split(separator: " ").map{ String($0) }
    
    if input[0] == "push"{
        stack.append(Int(input[1])!)
    } else if input[0] == "top"{
        if !stack.isEmpty {
            print(stack[stack.count - 1])
        } else {
            print(-1)
        }
    } else if input[0] == "size"{
        print(stack.count)
    } else if input[0] == "pop"{
        if !stack.isEmpty {
            print(stack.removeLast())
        } else {
            print(-1)
        }
    } else if input[0] == "empty"{
        if stack.isEmpty {
            print(1)
        } else {
            print(0)
        }
    }
}
