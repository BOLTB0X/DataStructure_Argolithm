//
//  main.swift
//  2512 예산
//  https://www.acmicpc.net/problem/2512
//  Created by KyungHeon Lee on 2023/09/14.
//

import Foundation

let N = Int(readLine()!)!
let budgets = readLine()!.split(separator: " ").map { Int(String($0))! }
let M = Int(readLine()!)!

var start: Int = 0
var end: Int = budgets.max()!

while start <= end {
    let mid = (start+end)/2
    
    var tot: Int = 0
    for budget in budgets {
        if budget <= mid {
            tot += budget
        } else {
            tot += mid
        }
    }
    
    if tot <= M {
        start = mid + 1
    } else {
        end = mid - 1
    }
}

print(end)
