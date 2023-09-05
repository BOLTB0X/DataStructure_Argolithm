//
//  main.swift
//  2529 부등호
//  https://www.acmicpc.net/problem/2529
//  Created by KyungHeon Lee on 2023/09/04.
//

import Foundation

let input1 = Int(readLine()!)!
let input2 = readLine()!.split(separator: " ").map { String ($0) }

let ret = solution(input1, input2)

for r in ret {
    print(r)
}

func solution(_ k: Int, _ inEqualities: [String]) -> [String] {
    var answer:[String] = []
    var visited: [Bool] = Array(repeating: false, count: 10)
    var maxRes:String = "-9876543210"
    var minRes:String = "9876543210"
    
    func DFS(_ numbers: [String], _ depth: Int) {
        if depth == k+1 {
            if  Int(numbers.joined())! > Int(maxRes)! {
                maxRes = numbers.joined()
            }
            
            if  Int(numbers.joined())! < Int(minRes)! {
                minRes = numbers.joined()
            }
            
            return
        }
        
        for i in 0...9 {
            if visited[i] {
                continue
            }
            
            if numbers.isEmpty {
                visited[i] = true
                DFS(numbers+[String(i)], depth+1)
                visited[i] = false
            } else {
                if inEqualities[depth-1] == ">" && Int(numbers[depth-1])! > i {
                    visited[i] = true
                    DFS(numbers+[String(i)], depth+1)
                    visited[i] = false
                } else if inEqualities[depth-1] == "<" && Int(numbers[depth-1])! < i {
                    visited[i] = true
                    DFS(numbers+[String(i)], depth+1)
                    visited[i] = false
                }
            }
        }
        return
    }
    
    DFS([], 0)
    answer = [maxRes, minRes]
    
    return answer
}
