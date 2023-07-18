// 2021 KAKAO BLIND RECRUITMENT 메뉴 리뉴얼
import Foundation

var comArr:[String] = []

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var answer:[String] = []
    
    for c in course {
        comArr = [] 
        // c만큼 코스요리 결정하기
        for order in orders {
            let orderArr = order.map {String($0)}
            //print(orderArr)
            combination(arr:orderArr, com: [], cur: 0, lim: c, level: 0) // 조합 생성
        }
        //print(comArr)
        var countDic: [String:Int] = [:]
        
        for com in comArr {
            for order in orders {
                if isAllContains(com, order) {
                    if let cnt = countDic[com] {
                        countDic[com] = cnt + 1
                    } else {
                        countDic[com] = 1
                    }
                }
            }
        }
        
        //print(countDic)
        if let maxValue = countDic.values.max() {
            for (key, value) in countDic {
                if value == maxValue && value != 1 {
                    answer.append(key)
                }
            }
        }
    }
    return answer.sorted()
}

func combination(arr:[String], com:[String], cur: Int, lim: Int, level: Int) {
    if lim == level {
        let sortedCom = com.sorted()
        let strCom = sortedCom.joined()
        if !comArr.contains(strCom) {
            comArr.append(strCom)
        }
        return
    }
    
    for i in cur..<arr.count {
        combination(arr: arr, com: com + [arr[i]], cur: i+1, lim: lim , level: level + 1)
    }
    return
}

func isAllContains(_ com: String, _ order:String) -> Bool {
    var arr1 = com.map{String($0)}
    var arr2 = order.map{String($0)}
    
    for a1 in arr1 {
        if !arr2.contains(a1) {
            return false
        }
    }
    
    return true
}