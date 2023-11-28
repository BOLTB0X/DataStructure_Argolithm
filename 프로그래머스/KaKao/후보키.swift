// 2019 KAKAO BLIND RECRUITMENT 후보키
// https://school.programmers.co.kr/learn/courses/30/lessons/42890
import Foundation

func solution(_ relation:[[String]]) -> Int {
    var answer: Int = 0
    var candidateKeySet: [Set<Int>] = []
    
    for i in 1...relation[0].count {
        let currentTotalCase = combination(Array(0..<relation[0].count), i)
        
        for selectedCol in currentTotalCase {
            let candidateKey = makeCandidateKey(relation, selectedCol)
            
            // 유일성, 최소성 체크
            if candidateKey.count != relation.count { continue }
            
            if !isMinimality(candidateKeySet, selectedCol) { continue }
            
            candidateKeySet.append(Set(selectedCol))
        }
    }
    
    answer = candidateKeySet.count
    return answer
}

func combination(_ n: [Int], _ r: Int) -> [[Int]] {
    var total: [[Int]] = []
    var visited = Array(repeating: false, count: n.count)
    
    func DFS(_ com: [Int], _ cur: Int, _ depth: Int) {
        if depth == r {
            total.append(com);
            return
        }
        
        for i in cur..<n.count {
            if visited[i] { continue }
            
            visited[i] = true
            DFS(com + [n[i]], i+1, depth+1)
            visited[i] = false
        }
    }
    
    DFS([], 0, 0)
    return total
}

func makeCandidateKey(_ relation: [[String]], _ selectedCol: [Int]) -> Set<String> {
    var ret: Set<String> = []
    for r in relation {
        ret.insert(selectedCol.reduce("") { $0 + r[$1]})
    }
    return ret
}

func isMinimality(_ candidateKeySet: [Set<Int>], _ selectedCol: [Int]) -> Bool {
    for current in candidateKeySet { // 최소성
        if current.isSubset(of: selectedCol) {
            return false
        }
    }
    
    return true
}