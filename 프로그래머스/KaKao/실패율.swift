// 2019 KAKAO BLIND RECRUITMENT 실패율
// https://school.programmers.co.kr/learn/courses/30/lessons/42889
import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var answer: [Int] = []
    var failArr: [(number: Int, fail: Double)] = []
    var player = stages.count
    
    let userState: [Int : Int] = updateCurrentUserStages(N, stages)

    for i in 1...N {
        failArr.append((number: i, fail: Double(userState[i]!)/Double(player)))
        player -= userState[i]!
    }
    
    answer = failArr.sorted { $0.fail > $1.fail }.map { $0.number}
    return answer
}

func updateCurrentUserStages(_ N:Int, _ stages:[Int]) -> [Int : Int] {
    var ret: [Int : Int] = [:]
    
    for i in 1...N+1 { ret[i] = 0 }
    
    for stage in stages { 
        ret[stage]! += 1 
    }
    
    return ret
}