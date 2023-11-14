// 2020 카카오 인턴십 수식 최대화
// https://school.programmers.co.kr/learn/courses/30/lessons/67257
import Foundation

var totalPermutation: [[String]] = []

func permutation(_ arr: [String], _ visited: [Bool], _ per: [String], _ depth: Int) {
    if depth == arr.count {
        if !totalPermutation.contains(per) { totalPermutation.append(per) }
        return
    }
    
    for i in 0..<arr.count {
        if visited[i] { continue }
        
        var visited = visited
        visited[i] = true
        permutation(arr, visited, per + [arr[i]], depth + 1)
        visited[i] = false
    }
}

func expressionSplited(_ expression: String) -> [String] {
    var ret: [String] = []
    var tmp: String = ""
    
    for e in expression {
        if e == "+" || e == "-" || e == "*" {
            ret.append(tmp)
            ret.append(String(e))
            tmp = ""
        } else { tmp.append(e) }
    }
    
    if ret.count > 0 { ret.append(tmp) }
    return ret
}

func operatorExp(_ num1: String, _ op: String, _ num2: String) -> String {
    switch op {
        case "+":
        return String(Int(num1)! + Int(num2)!)
        case "-":
        return String(Int(num1)! - Int(num2)!)
        default:
        return String(Int(num1)! * Int(num2)!)
    }
}

func getMaxValue(_ expression: [String] , _ per: [String]) -> Int64 {
    var expression = expression
    
    for p in per {
        var stack: [String] = []
        while !expression.isEmpty {
            let firstExp = expression.removeFirst()
            if firstExp == p {
                let tmp = operatorExp(stack.removeLast(), firstExp, expression.removeFirst());
                stack.append(tmp)
            } else { stack.append(firstExp) }
        }
        expression = stack
    }
    //print(expression)
    
    return abs(Int64(expression.first!)!)
}

func solution(_ expression:String) -> Int64 {
    var answer: Int64 = 0
    var expression = expressionSplited(expression)
    permutation(["+", "-", "*"], [false, false, false], [], 0)
    
    // print(totalPermutation)
    // print(expression)
    
    for per in totalPermutation {
        answer = max(answer, getMaxValue(expression, per))
    }
    
    return answer
}