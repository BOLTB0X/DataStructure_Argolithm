import Foundation

let board = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]

let board2 = [[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]

func solution(_ maps:[[Int]]) -> Int {
    var answer:Int = 0
    let N:Int = maps.count // 정방행렬이니
    
    // 거리 자취를 담을 배열
    var dist = Array(repeating: Array(repeating: 0, count: N), count: N)
    //  상하좌우
    let dy = [-1, 1, 0, 0]
    let dx = [0, 0, -1, 1]

    // 너비우선탐색
    func BFS(_ currentY:Int, _ currentX: Int) -> Int {
        // 사용할 큐를 임의로 만들어줌
        var que:[[Int]] = [[currentY, currentX]]
        dist[currentY][currentX] = 1
        
        while que.count > 0 {
            let cur = que.first! // 옵셔널 조심
            que.removeFirst() // 선입선출
            
            // 상하좌우 탐색
            for i in 0..<4 {
                // 다음 이동할 좌표들
                let ny = cur[0]+dy[i]
                let nx = cur[1]+dx[i]
                
                
                // 범위 내인지 체크
                if ny < 0 || nx < 0 || ny >= N || nx >= N {
                    continue
                }
                
                // 벽인 경우이거나 재방문인 경우
                if maps[ny][nx] == 0 || dist[ny][nx] != 0 {
                    continue
                }
                    
                // 자취 처리
                dist[ny][nx] = dist[cur[0]][cur[1]] + 1
                que.append([ny, nx])
            }
        }
        
        // 마지막 위치 반환
        return dist[N-1][N-1]
    }
    
    answer = BFS(0,0)
    // 문제 조건 조심
    return answer == 0 ? -1 : answer
}

print(solution(board))
print(solution(board2))
