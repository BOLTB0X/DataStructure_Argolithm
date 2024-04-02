//
//  main.swift
//  10845 큐
//  https://www.acmicpc.net/problem/10845
//  Created by KyungHeon Lee on 2023/08/08.
//

import Foundation

let N = Int(readLine()!)
var que: [Int] = []

for _ in 0..<N! {
    let input = readLine()!.split(separator: " ").map{ String($0) }
    
    if input[0] == "push" {
        que.append(Int(input[1])!)
    } else if input[0] == "front" {
        if !que.isEmpty {
            print(que[0])
        } else {
            print(-1)
        }
    } else if input[0] == "back" {
        if !que.isEmpty {
            print(que[que.count-1])
        } else {
            print(-1)
        }
    } else if input[0] == "size" {
        print(que.count)
    } else if input[0] == "pop" {
        if !que.isEmpty {
            print(que.removeFirst())
        } else {
            print(-1)
        }
    } else if input[0] == "empty" {
        if que.isEmpty {
            print(1)
        } else {
            print(0)
        }
    }
}

