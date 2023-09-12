//
//  main.swift
//  20920 영단어 암기는 괴로워
//  https://www.acmicpc.net/problem/20920
//  Created by KyungHeon Lee on 2023/09/12.
//

import Foundation

let NM = readLine()!.split(separator: " ").map{ Int(String($0))! }
var vocaDic: [String: Int] = [:]

var answer:[String] = []


for _ in 0..<NM[0] {
    let voca = readLine()!
    
    if let _ = vocaDic[voca] {
        vocaDic[voca]? += 1
    } else {
        vocaDic[voca] = 1
    }
}

let sortedKeys = vocaDic.keys.sorted { (key1, key2) -> Bool in
    if vocaDic[key1]! != vocaDic[key2]! {
        return vocaDic[key1]! > vocaDic[key2]!
    } else if key1.count != key2.count {
        return key1.count > key2.count
    } else {
        return key1 < key2
    }
}

for key in sortedKeys {
    if key.count >= NM[1] {
        print(key)
    }
}

