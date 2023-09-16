//
//  main.swift
//  3758 KCPC
//  https://www.acmicpc.net/problem/3758
//  Created by KyungHeon Lee on 2023/09/15.
//

import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
    let cmd = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let n = cmd[0]
    let k = cmd[1]
    let t = cmd[2]
    let m = cmd[3]
    
    var score = Array(repeating: Array(repeating: 0, count: k), count: n)
    var submit = Array(repeating: 0, count: n)
    var lastest = Array(repeating: 0, count: n)
    
    for i in 0..<m {
        // 팀 ID i, 문제 번호 j, 획득한 점수 s
        let info = readLine()!.split(separator: " ").map{ Int(String($0))! }
        score[info[0]-1][info[1]-1] = max(info[2], score[info[0]-1][info[1]-1])
        submit[info[0]-1] += 1
        lastest[info[0]-1] = i
    }
    
    var answer: Int = 1
    var teams: [Int: (score: Int, submit: Int, lastest: Int)] = [:]
    //print(score)
    for i in 0..<n {
        teams[i+1] = (score[i].reduce(0,+), submit[i], lastest[i])
    }
    
    //print(teams)
    let sortedTeams = teams.sorted { a,b -> Bool in
        if a.value.score == b.value.score {
            if a.value.submit == b.value.submit {
                return a.value.lastest < b.value.lastest
            }
            return a.value.submit < b.value.submit
        }
        return a.value.score > b.value.score
    }.map { $0.key}
    
    //print(sortedTeams)
    
    for team in sortedTeams {
        if team == t {
            print(answer)
            break
        }
        answer += 1
    }
}


