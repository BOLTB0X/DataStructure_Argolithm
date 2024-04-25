import Foundation

func solution(_ n:Int, _ m:Int, _ section:[Int]) -> Int {
    var answer: Int = 0, maxIdx: Int = 0
    
    for i in section.indices {
        if section[i] < maxIdx { continue }
        
        answer += 1
        maxIdx = section[i] + m
    }
    return answer
}