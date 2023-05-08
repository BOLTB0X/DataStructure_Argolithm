import Foundation

func solution(_ n:Int, _ edge:[[Int]]) -> Int {
    var answer:Int = 0
    var adjList = Array(repeating: [Int](), count: n+1) // 인접리스트
    var dist1 = Array(repeating: 0, count:n+1) // 거리 배열 BFS 용
    var dist2 = Array(repeating: Int.max, count:n+1) // dijikstra용
    var maxDepth:Int = Int.min // 최댓값을 위해
    
    // 너비우선탐색
    func BFS(_ start:Int) {
        var que:[Int] = [start]
        var depth:Int = 0
        dist1[start] = 1
        
        // 큐가 비어질때까지
        while que.count > 0 {
            var cur = que.removeFirst()
            
            for i in adjList[cur] {
                // 재방문
                if dist1[i] != 0 {
                    continue
                }
                
                dist1[i] = dist1[cur]+1 // 거리 자취를 남김
                maxDepth = max(maxDepth, dist1[i]) // 최댓값
                que.append(i)
            }
        }
        return
    }
    
    // dijikstra
    func dijikstra(_ start:Int) {
        var que:[Int] = [start]
        dist2[0] = 0
        dist2[1] = 1
        
        while que.count > 0 {
            let cur = que.removeFirst()
            
            for next in adjList[cur] {
                // 재방문
                if dist2[next] <= dist2[cur]+1 {
                    continue
                }
                
                dist2[next] = dist2[cur]+1
                maxDepth = max(maxDepth, dist2[next])
                que.append(next)
            }
        }
    }
    
    // 인접 리스트 생성
    for e in edge {
        adjList[e[0]].append(e[1])
        adjList[e[1]].append(e[0])
    }
    
    // BFS(1) // 탐색 시작
    dijikstra(1)
    
    // 최댓값 개수 체크
    answer = dist2.filter({maxDepth == $0}).count
    
    return answer
}

print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))
