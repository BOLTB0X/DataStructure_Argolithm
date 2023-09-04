import Foundation

func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    var answer:Int = Int.max
    var visited:[Bool] = Array(repeating: false, count: words.count)
    
    func check(_ cur: [String], _ next: [String]) -> Bool {
        var cnt:Int = 0
        
        for i in 0..<cur.count {
            if cur[i] != next[i] {
                cnt += 1
            }
        }
        
        return cnt == 1 ? true : false
    }
    
    func DFS(_ cur: String, _ depth: Int) {
        if cur == target {
            answer = min(depth, answer)
            return
        }
        
        for i in 0..<words.count {
            if visited[i] {
                continue
            }
            
            if !check(cur.map{String($0)}, words[i].map{String($0)}) {
                continue
            }
            
            visited[i] = true
            DFS(words[i], depth+1)
            visited[i] = false
        }
        return
    }
    
    if words.contains(target) {
        DFS(begin, 0)
    } else {
        answer = 0
    }
    
    return answer
}