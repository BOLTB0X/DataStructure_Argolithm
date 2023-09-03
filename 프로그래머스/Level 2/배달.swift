// https://school.programmers.co.kr/learn/courses/30/lessons/12978
import Foundation

func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var answer = 0
    var adj:[[Int]] = Array(repeating: Array(repeating: Int.max, count: N+1), count: N+1)
    
    func dijkstra(_ startNode: Int) -> Int {
        var dist:[Int] = Array(repeating: Int.max, count: N+1)
        var que:[(node: Int, cost: Int)] = []
        var qIdx:Int = 0
        
        que.append((startNode, 0))
        dist[startNode] = 0
        
        while qIdx < que.count {
            let cur = que[qIdx]
            qIdx += 1
            
            for next in 1...N {
                if adj[cur.node][next] == Int.max {
                    continue
                }
                
                if cur.cost + adj[cur.node][next] >= dist[next] {
                    continue
                }
                
                que.append((next, cur.cost + adj[cur.node][next]))
                dist[next] = cur.cost + adj[cur.node][next]
            }
        }
        
        return dist.filter { $0 <= k }.count
    }
    
    for r in road {
        adj[r[0]][r[1]] = min(r[2], adj[r[0]][r[1]])
        adj[r[1]][r[0]] = min(r[2], adj[r[1]][r[0]])
    }

    answer = dijkstra(1)

    return answer
}