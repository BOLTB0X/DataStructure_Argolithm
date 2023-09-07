import Foundation

func solution(_ priorities:[Int], _ location:Int) -> Int {
    var answer:Int = 0
    var pq:[Int] = []
    var que:[(Int, Int)] = []
    
    for i in 0..<priorities.count {
        que.append((i, priorities[i]))
        pq.append(priorities[i])
    }
    
    pq.sort(by: >)
    
    while !pq.isEmpty {
        let cur = que.removeFirst()
        
        if cur.1 == pq.first! {
            answer += 1
            pq.removeFirst()
            
            if cur.0 == location {
                break
            }
        } else {
            que.append(cur)
        }
    }
    
    return answer
}