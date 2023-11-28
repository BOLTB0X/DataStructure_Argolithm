// https://school.programmers.co.kr/learn/courses/30/lessons/72413
import Foundation

func solution(_ n:Int, _ s:Int, _ a:Int, _ b:Int, _ fares:[[Int]]) -> Int {
    var answer: Int = 0
    var adj = Array(repeating: Array(repeating: n*100000+1, count: n+1), count: n+1)
    
    for fare in fares {
        adj[fare[0]][fare[1]] = fare[2]
        adj[fare[1]][fare[0]] = fare[2]
    }
    
    for i in 1...n { adj[i][i] = 0 }
    
    for k in 1...n {
        for i in 1...n {
            for j in 1...n {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j])
            }
        }
    }
    
    answer = adj[s][a] + adj[s][b]; 
    for node in 1...n where node != s { 
        if answer > adj[s][node] + adj[node][a] + adj[node][b]{
            answer = adj[s][node] + adj[node][a] + adj[node][b]
        }
    }
    return answer
}