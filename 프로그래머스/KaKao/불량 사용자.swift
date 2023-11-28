// 2019 카카오 개발자 겨울 인턴십 불량 사용자
// https://school.programmers.co.kr/learn/courses/30/lessons/64064
import Foundation

func solution(_ user_id:[String], _ banned_id:[String]) -> Int {
    var answer:Int = 0
    var bannedUserSet: Set<String> = []
    let bannedUserCase = permutation(user_id, banned_id)
    
    for userCase in bannedUserCase {
        if isPossibleBlock(userCase, banned_id) {
            bannedUserSet.insert(userCase.sorted().joined())
        }
    }
    
    answer = bannedUserSet.count
    return answer
}

func permutation(_ n:[String], _ r:[String]) -> [[String]] {
    var ret:[[String]] = []
    var visited = Array(repeating: false, count: n.count)
    
    func DFS(_ per:[String], _ depth:Int) {
        if depth == r.count {
            ret.append(per)
            return
        }
        
        for i in 0..<n.count {
            if visited[i] { continue }
            
            if n[i].count != r[depth].count { continue }
            
            visited[i] = true
            DFS(per + [n[i]], depth + 1)
            visited[i] = false
        }
    }
    
    DFS([], 0)
    return ret
}

func isPossibleBlock(_ per:[String], _ banned_id:[String]) -> Bool {
    var ret:[String] = []
    let per = per.map { Array($0) }
    let banned_id = banned_id.map { Array($0)}

    for i in 0..<per.count {
        for j in 0..<per[i].count {
            if per[i][j] == banned_id[i][j] { continue }
        
            if banned_id[i][j] == "*" { continue }
            
            return false
        }
    }
    
    return true
}