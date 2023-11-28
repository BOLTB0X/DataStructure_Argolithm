// 2022 KAKAO BLIND RECRUITMENT 신고 결과 받기
// https://school.programmers.co.kr/learn/courses/30/lessons/92334
import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var answer: [Int] = []
    var orderDic: [String: Set<String>] = [:]
    var orderedDic: [String : Int] = [:]
    
    for id in id_list {
        orderDic[id] = []
        orderedDic[id] = 0
    }
    
    for info in report {
        let splitedInfo = info.components(separatedBy: " ")
        orderDic[splitedInfo[0]]!.insert(splitedInfo[1])
    }
    
    for value in orderDic.values {
        for v in value { 
            orderedDic[v]! += 1
        }
    } 
    
    for id in id_list {
        var cnt = 0
        for orderedId in orderDic[id]! {
            cnt += (orderedDic[orderedId]! >= k ? 1 : 0)
        }
        
        answer.append(cnt)
    }
    
    return answer
}