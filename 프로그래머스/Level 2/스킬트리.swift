// https://school.programmers.co.kr/learn/courses/30/lessons/49993
import Foundation

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    var answer: Int = 0
    var skill = skill.map {$0}
    
    for trees in skill_trees {
        var que = skill.map {$0}
        var qIdx = 0
        var flag = true
        for t in trees {
            if que.contains(t) {
                if t == que[qIdx] {
                    qIdx += 1  
                } else {
                    flag = false
                    break;
                }
            }
        }
        
        if flag {
            answer += 1
        }
    }
    
    
    return answer
}