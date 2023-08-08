//
//  main.swift
//  10866 덱
//  https://www.acmicpc.net/problem/10866
//  Created by KyungHeon Lee on 2023/08/08.
//

import Foundation

let N = Int(readLine()!)
var dq: [Int] = []

for _ in 0..<N! {
    let input = readLine()!.split(separator: " ").map{ String($0) }
    
    if input[0] == "push_front" {
        dq.insert(Int(input[1])!, at: 0)
    } else if input[0] == "push_back" {
        dq.append(Int(input[1])!)
    } else if input[0] == "pop_front" {
        if !dq.isEmpty {
            print(dq.removeFirst())
        } else {
            print(-1)
        }
    } else if input[0] == "pop_back" {
        if !dq.isEmpty {
            print(dq.removeLast())
        } else {
            print(-1)
        }
    } else if input[0] == "size" {
        print(dq.count)
    } else if input[0] == "front" {
        if !dq.isEmpty {
            print(dq.first!)
        } else {
            print(-1)
        }
    } else if input[0] == "back" {
        if !dq.isEmpty {
            print(dq.last!)
        } else {
            print(-1)
        }
    } else if input[0] == "empty" {
        if dq.isEmpty {
            print(1)
        } else {
            print(0)
        }
    }
}
