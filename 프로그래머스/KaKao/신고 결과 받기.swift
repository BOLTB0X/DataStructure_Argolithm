// 2022 KAKAO BLIND RECRUITMENT 신고 결과 받기
import Foundation

func solution(_ id_list:[String], _ report:[String], _ k:Int) -> [Int] {
    var answer:[Int] = []
    var attackDic: [String:[String]] = [:]
    var attackedDic: [String:Int] = [:]
    var orderDic: [String:Int] = [:]
    
    for id in id_list {
        attackDic[id] = []
        attackedDic[id] = 0
        orderDic[id] = 0
    }
    
    for r in report {
        let splitedR = r.components(separatedBy: " ")
        
        if var values = attackDic[splitedR[0]] {
            if !values.contains(splitedR[1]) {
                attackDic[splitedR[0]]?.append(splitedR[1])
                attackedDic[splitedR[1]]? += 1
            }
        }
    }
    //print(attackDic, attackedDic)
    for (key, value) in attackDic {
        var cnt:Int = 0
        for v in value {
            if attackedDic[v]! >= k {
                cnt += 1
            }
        }
        orderDic[key] = cnt
    }
    //print(orderDic)
    
    for i in 0..<id_list.count {
        answer.append(orderDic[id_list[i]]!)
    }
    return answer
}