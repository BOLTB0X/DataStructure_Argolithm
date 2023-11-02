// https://school.programmers.co.kr/learn/courses/30/lessons/178871
import Foundation

func solution(_ players:[String], _ callings:[String]) -> [String] {
    var answer: [String] = players
    var rank: [String: Int] = [:]
    
    for player in players.enumerated() {
        rank[player.1] = player.0
    }
    
    //print(rank)
    
    for calling in callings {
        let cur = rank[calling]!
        let prev = cur - 1
        rank[calling]? -= 1
        rank[answer[prev]]? += 1
        answer.swapAt(prev, cur)

    }
    //print(rank)
    return answer
}