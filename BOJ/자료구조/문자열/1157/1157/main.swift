//
//  main.swift
//  1157 단어 공부
//  https://www.acmicpc.net/problem/1157
//  Created by KyungHeon Lee on 2023/08/14.
//

import Foundation

let inputStr = readLine()!.uppercased().map{String($0)}

var answer:String = ""
var alpDic: [String: Int] = ["A": 0, "B": 0, "C": 0, "D": 0, "E": 0,
                              "F": 0, "G": 0, "H": 0, "I": 0, "J": 0, "K": 0,
                              "L": 0, "M": 0, "N": 0, "O": 0, "P": 0, "Q": 0,
                              "R": 0, "S": 0, "T": 0, "U": 0, "V": 0, "W": 0,
                              "X": 0, "Y": 0, "Z": 0]

for i in inputStr {
    alpDic[i]! += 1
}

if let maxVal = alpDic.max(by: { $0.value < $1.value }) {
    for (key, value) in alpDic {
        if key == maxVal.key && value == maxVal.value {
            answer = key
        } else if key != maxVal.key && value == maxVal.value {
            answer = "?"
            break
        }
    }
}

print(answer)

