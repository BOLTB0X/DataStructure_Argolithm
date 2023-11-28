// 2020 카카오 인턴십 보석 쇼핑
// https://school.programmers.co.kr/learn/courses/30/lessons/67258
import Foundation

func solution(_ gems:[String]) -> [Int] {
    var answer:[Int] = [0, gems.count]
    var gemsDict:[String:Int] = [:]
    
    let gemsTypeCount = Set(gems).count
    let gemsSize = gems.count
    var start = 0
    var end = 0
    
    gemsDict[gems.first!] = 1
    
    // 투포인터
    while start < gemsSize && end < gemsSize && start <= end {
        if gemsDict.count == gemsTypeCount {
            if answer[1] - answer[0] > end - start {
                answer[0] = start + 1
                answer[1] = end + 1
            }
            
            gemsDict[gems[start], default: 0] -= 1
            if gemsDict[gems[start]]! <= 0 {
                gemsDict[gems[start]] = nil
            }
            start += 1
            
        } else {
            end += 1
            if end == gemsSize { break }
            gemsDict[gems[end], default: 0] += 1 
        }
    }
    
    return answer
}