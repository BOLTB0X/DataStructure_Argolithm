// 2020 카카오 인턴십 수식 최대화
import Foundation

func solution(_ expression:String) -> Int64 {
    var answer:Int64 = 0
    let expression = splitNumberAndOp(expression)
    let priorityCase = permutation(["+","-","*"], 3)

    for per in priorityCase {
        answer = max(answer, calculateExpression(per, expression))
    }
    return answer
}

func splitNumberAndOp(_ expression:String) -> [String] {
    var ret:[String] = []
    var tempString:String = ""
    
    for exp in expression {
        if exp == "+" || exp == "-" || exp == "*" {
            ret.append(tempString)
            ret.append(String(exp))
            tempString = ""
        } else {
            tempString.append(exp)
        }
    }
    ret.append(tempString)
    return ret
}

func permutation(_ n:[Character], _ r: Int) -> [[String]] {
    var ret:[[String]] = []
    var visited = Array(repeating: false, count: n.count)
    
    func DFS(_ per:[Character], _ depth: Int) {
        if depth == r {
            ret.append(per.map { String($0) })
            return
        }
        
        for i in 0..<n.count {
            if visited[i] { continue }
            
            visited[i] = true
            DFS(per + [n[i]], depth + 1)
            visited[i] = false
        }
    }
    
    DFS([], 0)
    return ret
}

func calculateExpression(_ per: [String], _ expression: [String]) -> Int64 {
    var expression = expression
    
    func operatorExp(_ num1:Int64, _ op:String, _ num2:Int64) -> String {
        var ret: Int64 = 0
        switch op {
            case "+":
            ret = num1 + num2
            break
            case "-":
            ret = num1 - num2
            break
            default:
            ret = num1 * num2
            break
        }
        
        return String(ret)
    }
    
    for p in per {
        var stack:[String] = []
        while !expression.isEmpty {
            let front = expression.removeFirst()
            
            if front == p {
                let value = operatorExp(Int64(stack.removeLast())!, front, Int64(expression.removeFirst())!)
                stack.append(value)
            } else {
                stack.append(front)
            }
        }
        expression = stack
    }
    
    return abs(Int64(expression.first!)!)
}