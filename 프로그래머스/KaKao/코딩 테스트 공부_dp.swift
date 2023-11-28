// 2022 KAKAO TECH INTERNSHIP 코딩 테스트 공부
// https://school.programmers.co.kr/learn/courses/30/lessons/118668
// dp
import Foundation

func solution(_ alp:Int, _ cop:Int, _ problems:[[Int]]) -> Int {
    var answer: Int = 0
    let maxAlp: Int = problems.map{ $0[0] }.max()!
    let maxCop: Int = problems.map { $0[1] }.max()!
    
    let alp = min(maxAlp, alp)
    let cop = min(maxCop, cop)
    
    var dp = Array(repeating: Array(repeating: Int.max, count: maxCop + 1), count: maxAlp+1)
    
    
    dp[alp][cop] = 0 
    for i in alp...maxAlp {
        for j in cop...maxCop {
            if i < maxAlp {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1)
            }
            
            if j < maxCop {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1)
            }
            
            for problem in problems {
                let alp_req = problem[0]
                let cop_req = problem[1]
                let alp_rwd = problem[2]
                let cop_rwd = problem[3]
                let cost = problem[4]
                
                if i >= alp_req && j >= cop_req {
                    let nxtAlp = min(i + alp_rwd, maxAlp)  
                    let nxwCop = min(j + cop_rwd, maxCop)
                    dp[nxtAlp][nxwCop] = min(dp[nxtAlp][nxwCop], dp[i][j] + cost)
                }
            }
        }
    }
    
    answer = dp[maxAlp][maxCop]
    return answer
}