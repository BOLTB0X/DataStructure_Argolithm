// 2022 KAKAO TECH INTERNSHIP 등산코스 정하기
// https://school.programmers.co.kr/learn/courses/30/lessons/118669
import Foundation

func solution(_ n:Int, _ paths:[[Int]], _ gates:[Int], _ summits:[Int]) -> [Int] {
    var answer: [Int] = [Int.max, Int.max]
    let adj: [[(node:Int, cost:Int)]] = createAdjList(n, paths)
    let summitsDic = createDictionary(summits)
    
    var dist = Array(repeating: Int.max, count:n+1)
    var que:[(node: Int, cost: Int)] = []
    var head:Int = 0
    
    for gate in gates { 
        que.append((gate, 0)) 
        dist[gate] = 0
    }
    
    while head < que.count {
        let cur = que[head]
        head += 1
        
        if dist[cur.node] != cur.cost { continue }
        
        for nxt in adj[cur.node] {
            let maxCost = max(cur.cost, nxt.cost)
            
            if dist[nxt.node] <= maxCost { continue }
            
            dist[nxt.node] = maxCost
            
            if let _ = summitsDic[nxt.node] {
                continue
            }
            que.append((nxt.node, dist[nxt.node]))
        }
    }
    
    for summit in summits {
        if answer[1] > dist[summit] {
            answer = [summit, dist[summit]]
        } else if answer[1] == dist[summit] && answer[0] > summit {
            answer[0] = summit
        }
    }
    return answer
}

func createAdjList(_ n:Int , _ paths:[[Int]]) -> [[(Int, Int)]] {
    var ret = Array(repeating: [(nxt:Int, cost:Int)](), count: n+1)
    
    for path in paths {
        ret[path[0]].append((path[1], path[2]))
        ret[path[1]].append((path[0], path[2]))
    }
    
    return ret
}

func createDictionary(_ summits:[Int]) -> [Int:Bool] {
    var ret: [Int:Bool] = [:]
    
    for summit in summits {
        ret[summit] = true
    }
    
    return ret
}