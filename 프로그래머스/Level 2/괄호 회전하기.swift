// https://school.programmers.co.kr/learn/courses/30/lessons/76502
import Foundation

func solution(_ s:String) -> Int {
    var answer:Int = 0
    var sArr = s.map{ String($0) }
    
    func isCorrect(_ sArr: [String]) -> Bool {
        var stack:[String] = []
        
        for ch in sArr {
            if ch == "[" || ch == "(" || ch == "{" {
                stack.append(ch)
            } else {
                if stack.isEmpty {
                    return false
                } else {
                    if stack.last! == "[" && ch == "]" {
                        stack.removeLast()
                    } else if stack.last! == "(" && ch == ")" {
                        stack.removeLast()
                    } else if stack.last! == "{" && ch == "}" {
                        stack.removeLast()
                    }
                }
            }
        }
        return stack.isEmpty ? true : false 
    }
    
    for i in 0..<s.count {
        if isCorrect(sArr) {
            answer += 1
        }
        sArr.append(sArr.removeFirst())
    }
    
    return answer
}