//
//  main.swift
//  5073 삼각형과 세 변
//  https://www.acmicpc.net/problem/5073
//  Created by KyungHeon Lee on 2023/08/14.
//

import Foundation


while true {
    let abc = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    if abc[0] == 0 && abc[1] == 0 && abc[2] == 0 {
        break
    }

    if abc[1] + abc[2] <= abc[0] || abc[0] + abc[2] <= abc[1] || abc[0] + abc[1] <= abc[2] {
        print("Invalid")
    }
    else {
        if abc[0] == abc[1] && abc[1] == abc[2] {
            print("Equilateral")
        } else if (abc[0] == abc[1] && abc[1] != abc[2]) || (abc[1] == abc[2] && abc[2] != abc[0]) || (abc[0] == abc[2] && abc[1] != abc[2]) {
            print("Isosceles")
        } else {
            print("Scalene")
        }
    }
}

