//
//  main.swift
//  23971 ZOAC 4
//  https://www.acmicpc.net/problem/23971
//  Created by KyungHeon Lee on 2023/08/14.
//

import Foundation

let HWNM = readLine()!.split(separator: " ").map{ Int(String($0))! }

let a = Double(HWNM[0])/Double(HWNM[2]+1)
let b = Double(HWNM[1])/Double(HWNM[3]+1)

print(Int(ceil(a)*ceil(b)))
