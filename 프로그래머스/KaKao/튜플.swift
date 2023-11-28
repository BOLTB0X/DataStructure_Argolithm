// 2019 카카오 개발자 겨울 인턴십 튜플
// https://school.programmers.co.kr/learn/courses/30/lessons/64065
import Foundation

func solution(_ s:String) -> [Int] {
    var answer:[Int] = []
    let s = translateIntArrayFromTuple(s).sorted { $0.count < $1.count }
    
    for arr in s {
        for a in arr {
            if answer.contains(a) { continue }
            answer.append(a)
        }
    }
    return answer
}

func translateIntArrayFromTuple(_ s:String) -> [[Int]] {
    var ret:[[Int]] = []
    var s = s
    var tempArr: [Int] = []
    var tempString: String = ""
    var flag: Bool = false
    
    s.removeFirst()
    s.removeLast()
    
    s.forEach {
        if flag {
            if $0.isNumber {
                tempString.append($0)
            } else {
                tempArr.append(Int(tempString)!)
                if $0 == "}" {
                    ret.append(tempArr)
                    tempArr = []
                    flag = false
                }
                tempString = ""
            }
        } else if $0 == "{" {
            flag = true 
        }
    }
    
    return ret
}