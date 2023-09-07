//
//  main.swift
//  42885 구명보트
//  https://school.programmers.co.kr/learn/courses/30/lessons/42885
//  Created by KyungHeon Lee on 2023/09/07.
//

import Foundation

func solution(_ people: [Int], limit: Int) -> Int {
    var answer: Int = 0
    var left: Int = 0
    var right: Int = people.count-1
    
    let people = people.sorted(by: <)
    
    while left <= right {
        if people[left]+people[right] <= limit {
            left += 1
            right -= 1
        } else {
            right -= 1
        }
        answer += 1
    }
    return answer
}

print(solution([70, 50, 80, 50], limit: 100))
print(solution([70, 80, 50], limit: 100))
