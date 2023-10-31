//
//  main.swift
//  2798 블랙잭
//  https://www.acmicpc.net/problem/2798
//  Created by KyungHeon Lee on 2023/09/04.
//

import Foundation

let NM = readLine()!.split(separator: " ").map { Int($0)! }
let arr = readLine()!.split(separator: " ").map { Int($0)! }

func solution(_ N: Int, _ M: Int, _ cards: [Int]) -> Int {
  var answer: Int = 0

  for i in 0..<N {
    for j in i+1..<N {
      for k in j+1..<N {
        if cards[i]+cards[j]+cards[k] <= M {
          answer = max(answer, cards[i]+cards[j]+cards[k])
        }
      }
    }
  }

  return answer
}

print(solution(NM[0], NM[1], arr))
