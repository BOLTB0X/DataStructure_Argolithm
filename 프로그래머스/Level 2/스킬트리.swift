// https://school.programmers.co.kr/learn/courses/30/lessons/49993
import Foundation

func solution(_ skill:String, _ skill_trees:[String]) -> Int {
    var answer: Int = 0
    
    for tree in skill_trees {
        var que: [Character] = skill.map { $0 }
        var qIdx = 0;
        var flag = true
        
        for t in tree {
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