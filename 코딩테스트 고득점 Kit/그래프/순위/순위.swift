import Foundation

func solution(_ n:Int, _ results:[[Int]]) -> Int {
    var answer:Int = 0
    var adj:[[Int]] = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)
    
    for res in results {
        adj[res[0]][res[1]] = 1
        adj[res[1]][res[0]] = -1
    }
    
    for k in 1...n {
        for a in 1...n {
            for b in 1...n {
                if adj[a][k] == 1 && adj[k][b] == 1 {
                    adj[a][b] = 1
                } else if adj[a][k] == -1 && adj[k][b] == -1 {
                    adj[a][b] = -1
                }
            }
        }
    }
    
    for i in 1...n {
        var cnt: Int = 0
        for j in 1...n {
            if adj[i][j] == 0 {
                cnt += 1
            }
        }
        if cnt == 1 {
            answer += 1
        }
    }
    
    return answer
}