import Foundation

func solution(_ n:Int, _ results:[[Int]]) -> Int {
    var answer:Int = 0 // 정딥
    // 인접행렬
    var adjMat:[[Int]] = Array(repeating: Array(repeating: 99999999, count: n+1), count:n+1)
    
    for res in results {
        // 인접행렬에 표시
        // 즉 A선수가 B선수를 이긴다는 표시
        adjMat[res[0]][res[1]] = 1
    }
    
    // 자기 자신 0처리
    for i in 1...n {
        for j in 1...n {
            if i == j {
                adjMat[i][j] = 0
            }
        }
    }
    
    // 플로이드 워셜
    for k in 1...n {
        for i in 1...n {
            for j in 1...n {
                adjMat[i][j] = min(adjMat[i][j], adjMat[i][k]+adjMat[k][j])
            }
        }
    }
    
    // 행을 기준으로
    for i in 1...n {
        // 해당 열에 도달했는지 안했는지 세고
        // 즉 순위를 알 수 있는 것
        var cnt:Int = 0
        for j in 1...n {
            if adjMat[i][j] != 99999999 ||
            adjMat[j][i] != 99999999 {
                cnt += 1
            }
        }
        if cnt == n {
            answer += 1
        }
    }
    
    print(adjMat)
    return answer
}

print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
