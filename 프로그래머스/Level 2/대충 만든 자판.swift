// https://school.programmers.co.kr/learn/courses/30/lessons/160586?language=swift
import Foundation

func solution(_ keymap:[String], _ targets:[String]) -> [Int] {
    var answer:[Int] = []
    
    // 딕셔너리 생성
    var dic:[String:Int] = [:]
    
    for i in 0..<keymap.count {
        let tmp = keymap[i].map { String($0) }
        //print(tmp)
        for j in 0..<tmp.count {
            if let key = dic[tmp[j]] {
                dic[tmp[j]]! = min(j+1, dic[tmp[j]]!)
            } else {
                dic[tmp[j]] = j+1
            }
        }
    }
    
    for t in targets {
        let target = t.map{ String($0) }
        var cnt:Int = 0
        
        for tar in target {
            if let val = dic[tar] {
                cnt += val
            } else {
                cnt = -1
                break
            }
        }
        
        answer.append(cnt)
    }
    
    return answer
}