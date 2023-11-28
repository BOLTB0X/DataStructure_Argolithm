// 2021 KAKAO BLIND RECRUITMENT 메뉴 리뉴얼
// https://school.programmers.co.kr/learn/courses/30/lessons/72411
import Foundation

func combination(_ arrs: [String], _ r: Int) -> Set<String> {
    var totalCom: Set<String> = []
    
    func DFS(arr: [String] , com: [String], cur: Int, depth: Int) {
        if depth == r {
            let sortedCom = com.sorted { $0 < $1 }
            totalCom.insert(sortedCom.joined())
            return
        }
        
        for i in cur..<arr.count {
            DFS(arr: arr, com: com + [arr[i]], cur: i+1, depth: depth+1)
        }
    }
    
    for arr in arrs {
        DFS(arr: arr.map { String($0) }, com: [], cur: 0, depth: 0)
    }
    return totalCom
}

func getCountCourseDictionary(_ ordersCombination: Set<String>, _ orders:[String]) -> [String: Int] {
    var courseDict: [String: Int] = [:]
    
    for com in ordersCombination {
        for order in orders {
            if isOrder(com, order) {
                courseDict[com, default: 0] += 1
            }
        }
    }
    
    return courseDict
}

func isOrder(_ orderCombination: String, _ currentOrder: String) -> Bool {
    let orderCombination = orderCombination.map { String ($0) }
    let currentOrder = currentOrder.map { String($0) }
    
    for com in orderCombination {
        if !currentOrder.contains(com) {
            return false
        }
    }
    return true
}

func isAddCourse(_ courseDict: [String: Int], _ result: inout [String]) {
    if let maxCoursCombination = courseDict.values.max() {
        if maxCoursCombination == 1 { return }
            
        for (key, value) in courseDict {
            if value < maxCoursCombination { continue }
            result.append(key)
        }
    }
}

func solution(_ orders:[String], _ course:[Int]) -> [String] {
    var answer: [String] = []
    
    for currentCourse in course {
        let ordersCombination = combination(orders, currentCourse)
        let courseDict = getCountCourseDictionary(ordersCombination, orders)
        isAddCourse(courseDict, &answer)
    }
    
    answer.sort { $0 < $1 }
    return answer
}