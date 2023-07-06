//
//  main.swift
//  10430 나머지
//  https://www.acmicpc.net/problem/10430
//  Created by KyungHeon Lee on 2023/07/06.
//

import Foundation

let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
var a = arr[0]
var b = arr[1]
var c = arr[2]

print("\((a + b) % c)")
print("\(((a % c) + (b % c)) % c)")
print("\((a * b) % c)")
print("\(((a % c) * (b % c)) % c)")
