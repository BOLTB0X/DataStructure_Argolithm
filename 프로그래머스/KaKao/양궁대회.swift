// 2022 KAKAO BLIND RECRUITMENT 양궁대회
// https://school.programmers.co.kr/learn/courses/30/lessons/92342
import Foundation

func solution(_ n:Int, _ info:[Int]) -> [Int] {
    var answer: [Int] = [-1]
    var maxDiff: Int = -1
    let totalCase = combination(Array(0...10), n)
    
    for arrows in totalCase {
        let lion = getLionInfo(arrows)
        let scores: (apeach: Int, lion: Int) = calculateScore(info, lion)
        
        if scores.apeach < scores.lion {
            if maxDiff < scores.lion - scores.apeach {
                maxDiff = scores.lion - scores.apeach
                answer = lion
            }
        }
    }
    return answer
}

func combination(_ n: [Int], _ r: Int) -> [[Int]] {
    var ret: [[Int]] = []
    
    func DFS(_ com: [Int], _ cur: Int, _ depth: Int) {
        if depth == r {
            ret.append(com)
            return
        }
        
        for i in cur..<n.count {            
            DFS(com + [n[i]], i, depth+1)
        }
    }
    
    DFS([], 0, 0)
    return ret
}

func getLionInfo(_ arrows: [Int]) -> [Int] {
    arrows.reduce(into: Array(repeating: 0, count: 11)) { $0[10-$1] += 1 }
}

func calculateScore(_ apeach: [Int], _ lion: [Int]) -> (Int, Int) {
    var ret: (Int, Int) = (0, 0)
    
    for i in 0...10 {
        if apeach[i] == 0 && lion[i] == 0 { continue }
        
        if apeach[i] < lion[i] {
            ret.1 += (10-i)
        } else {
            ret.0 += (10-i)
        }
    }
    
    return ret
}