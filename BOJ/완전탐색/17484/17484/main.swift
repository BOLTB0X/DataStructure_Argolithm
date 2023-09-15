//
//  main.swift
//  17484 진우의 달 여행 (Small)
//  https://www.acmicpc.net/problem/17484
//  Created by KyungHeon Lee on 2023/09/15.
//

import Foundation

let NM = readLine()!.split(separator: " ").map{ Int(String($0))!}
var board: [[Int]] = []

for _ in 0..<NM[0] {
    board.append(readLine()!.split(separator: " ").map{ Int(String($0))!})
}

print(solution(NM[0], NM[1], board))

func solution(_ N: Int, _ M: Int, _ boardMap: [[Int]]) -> Int {
    var answer = Int.max
    let dir = [-1, 0, 1]
    
    func DFS(_ cur: (x: Int, y: Int), _ preDir: Int, _ tot: Int) {
        if cur.x == N-1 {
            answer = min(answer, tot)
            return
        }
        for d in dir {
            let nx = cur.x + 1
            let ny = cur.y + d
            
            if nx < 0 || ny < 0 || nx >= N || ny >= M {
                continue
            }
            
            if preDir == d {
                continue
            }
            
            DFS((nx, ny), d, tot+boardMap[nx][ny])
        }
        return
    }
    
    for i in 0..<M {
        DFS((0, i), -2, boardMap[0][i])
    }
    return answer
}
