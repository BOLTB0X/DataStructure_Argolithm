// https://school.programmers.co.kr/learn/courses/30/lessons/12973
import Foundation

func solution(_ s:String) -> Int{
    var s = s.map{ String($0)}
    var stack:[String] = Array(repeating: "", count: 1000000)
    var top:Int = -1
    
    for ch in s {
        if top == -1 {
            top += 1
            stack[top] = ch
        } else {
            if stack[top] == ch {
                stack[top] = ""
                top -= 1
            } else {
                top += 1
                stack[top] = ch
            }
        }
    }

    return top == -1 ? 1 : 0
}