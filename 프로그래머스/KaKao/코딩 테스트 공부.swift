// 2022 KAKAO TECH INTERNSHIP 코딩 테스트 공부
// https://school.programmers.co.kr/learn/courses/30/lessons/118668
// 다익스트라? BFS?
import Foundation

func solution(_ alp:Int, _ cop:Int, _ problems:[[Int]]) -> Int {
    var answer: Int = 0
    let maxAlp = problems.map{ $0[0] }.max()!
    let maxCop = problems.map{ $0[1] }.max()!
    
    var problems = problems
    problems.append([0, 0, 1, 0, 1])
    problems.append([0, 0, 0, 1, 1])
    problems.sort { 
        return $0[0] == $1[0] ? $0[1] < $1[1] : $0[0] < $1[0]
    }

    var dist = Array(repeating: Array(repeating: 10001, count: maxCop + 1), count: maxAlp + 1)
    
    let alp = min(alp, maxAlp)
    let cop = min(cop, maxCop)
    var que: [(a: Int, c: Int, cost: Int)] = []
    var head = 0
    
    dist[alp][cop] = 0
    que.append((a: alp, c: cop, cost: 0))
    
    while head < que.count {
        let cur = que[head]
        head += 1
        
        if dist[cur.a][cur.c] < cur.cost { continue }
        
        for problem in problems {
            let needAlp = problem[0]
            let needCop = problem[1]
            let getAlp = problem[2]
            let getCop = problem[3]
            let time = problem[4]
            
            if cur.a < needAlp || cur.c < needCop {
                if cur.a < needAlp && cur.c < needCop { break }
                continue
            }
            
            let nxtAlp = min(cur.a + getAlp, maxAlp)
            let nxtCop = min(cur.c + getCop, maxCop)
            
            if dist[nxtAlp][nxtCop] > dist[cur.a][cur.c] + time {
                dist[nxtAlp][nxtCop] = dist[cur.a][cur.c] + time
                que.append((a: nxtAlp, c:nxtCop , cost: dist[nxtAlp][nxtCop]))
            }
        }
    }
    
    answer = dist[maxAlp][maxCop]
    return answer
}