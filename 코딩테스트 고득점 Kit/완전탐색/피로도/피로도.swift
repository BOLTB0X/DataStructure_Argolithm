import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer:Int = 0
    var visited: [Bool] = Array(repeating: false, count: dungeons.count)
    var perArr:[[Int]] = []
    
    func permutation(per: [Int], depth: Int) {
        if depth == dungeons.count {
            perArr.append(per)
            return
        }
        
        for i in 0..<dungeons.count {
            if visited[i] {
                continue
            }
            
            visited[i] = true
            permutation(per: per+[i], depth: depth+1)
            visited[i] = false
        }
        return
    }
    
    permutation(per:[], depth: 0)
    
    for per in perArr {
        var cnt:Int = 0
        var cur:Int = k
        
        for p in per {
            if dungeons[p][0] > cur {
                continue
            }
            
            cnt += 1
            cur -= dungeons[p][1]
        }
        
        answer = max(answer, cnt)
    }
    return answer
}