import Foundation

func solution(_ n:Int, _ wires:[[Int]]) -> Int {
    // 개수의 차이 값을 최대한 맞춘다
    // 즉 절대값 중 최솟값을 쓴다는 말
    var answer = Int.max;
    // 인접행렬 이용
    var adjMat:[[Int]] = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)
    
    // MARK: adj식 BFS
    func BFS(_ start: Int) -> Int{
        var res: Int = 0
        var visited:[Bool] = Array(repeating: false, count: n+1)
        var que:[Int] = [start]
        visited[start] = true
        
        while (que.count > 0) {
            var cur = que.removeFirst()
            res += 1
            // 현재 인접행렬의 갯수만큼 ==> 연결되어있는 수만큼
            // 현재 행의 열들의 값이 0이면 미연결 1이면 연결
            for i in 1...n {
                // 재방문
                if visited[i] {
                    continue
                }
                
                // 미연결
                if adjMat[cur][i] == 0 {
                    continue;
                }
                
                visited[i] = true
                que.append(i) // 연결된 노드
            }
            
        }
        return res
    }
    
    
    // MARK: adj식 DFS
    func DFS(_ visited:[Bool], _ cur:Int, _ depth:Int) -> Int {
        var depth = depth
        var visited = visited
        visited[cur] = true
        
        for i in 1...n {
            if visited[i] {
                continue;
            }
            
            if adjMat[cur][i] == 0 {
                continue
            }
            
            depth = DFS(visited, i, depth+1)
        }
        
        return depth
    }

    
    // 인접행렬 연결
    for i in 0..<wires.count {
        // 양방향이므로
        adjMat[wires[i][0]][wires[i][1]] = 1
        adjMat[wires[i][1]][wires[i][0]] = 1
    }
    
    //print(adjMat)
    
    // for문으로 연결을 끊을 wire을 하나식 선정하며
    // 완전탐색 진행
    for i in 0..<wires.count {
        // 연결 해제
        adjMat[wires[i][0]][wires[i][1]] = 0
        adjMat[wires[i][1]][wires[i][0]] = 0
        
//        // 끊은 노드로 BFS 탐색
//        let ret1 = BFS(wires[i][0])
//        let ret2 = BFS(wires[i][1])
        var visited:[Bool] = Array(repeating: false, count: n+1)
        let ret1 = DFS(visited, wires[i][0],0)
        let ret2 = DFS(visited, wires[i][1],0)
        
        answer = min(answer, abs(ret1-ret2))
        
        // 다시 연결
        adjMat[wires[i][0]][wires[i][1]] = 1
        adjMat[wires[i][1]][wires[i][0]] = 1
    }
    
    return answer
}

let n1 = 9
let n2 = 4
let n3 = 7

let wires1 = [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]]
let wires2 = [[1,2],[2,3],[3,4]]
let wires3 = [[1,2],[2,7],[3,7],[3,4],[4,5],[6,7]]

print(solution(n1, wires1))
print(solution(n2, wires2))
print(solution(n3, wires3))
