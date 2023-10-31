// https://school.programmers.co.kr/learn/courses/30/lessons/181188
import Foundation

func solution(_ targets:[[Int]]) -> Int {
    var answer: Int = 1
    
    let sortedTargets = targets.sorted { $0[1] < $1[1] }
    //print(sortedTargets)
    var cmp = sortedTargets[0][1]
    
    for target in sortedTargets {
        if cmp <= target[0] {
            answer += 1
            cmp = target[1]
        }
    }
    return answer
}