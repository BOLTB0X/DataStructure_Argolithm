// https://school.programmers.co.kr/learn/courses/30/lessons/154538?language=swift
import Foundation

func solution(_ x:Int, _ y:Int, _ n:Int) -> Int {
    var answer:Int = -1
    var que:[Int] = []
    var queIdx:Int = 0
    var dist = Array(repeating: 0, count: 1000001)
    
    que.append(x)
    dist[x] = 1
    
    while queIdx < que.count {
        let cur = que[queIdx]
        queIdx += 1
        
        if cur == y {
            answer = dist[cur]-1
            break
        } else {
            if cur+n < 1000001 && dist[cur+n] == 0 {
                que.append(cur+n)
                dist[cur+n] = dist[cur]+1
            }
            
            if cur*2 < 1000001 && dist[cur*2] == 0 {
                que.append(cur*2)
                dist[cur*2] = dist[cur]+1
            }
            
            if cur*3 < 1000001 && dist[cur*3] == 0 {
                que.append(cur*3)
                dist[cur*3] = dist[cur]+1
            }
        }
    }
    
    return answer
}