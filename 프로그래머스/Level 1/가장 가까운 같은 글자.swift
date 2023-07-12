// https://school.programmers.co.kr/learn/courses/30/lessons/142086?language=swift
import Foundation

func solution(_ s:String) -> [Int] {
    var answer:[Int] = []
    var s = s.map {String($0)}
    var cmp:[String] = []
    
    for i in s.enumerated() {
        if cmp.contains(i.1) == true {
            let targetIndex = cmp.lastIndex(of: i.1)!
            answer.append(i.0 - targetIndex)
        } else { // 처음 나온 경우
            answer.append(-1)
        }
        cmp.append(i.1)
    }

    return answer
}