import Foundation

func solution(_ s:String) -> Bool {
    var ans:Bool = false
    var sArr = s.map{ String($0) } // 배열
    var stack:[Int] = [] // 스택
    
    for i in 0..<sArr.count {
        // open이면
        if sArr[i] == "(" {
            stack.append(1) // 스택에 넣어줌
        } else { // close를 직면하는 경우
            // 스택이 비어있지 않고 open이 있는 경우
            if stack.count > 0 && stack[0] == 1 {
                ans = true
                stack.removeFirst() // pop
            } else {
                ans = false
                break
            }
        }
    }
    
    if stack.count > 0 {
        ans = false
    }
    return ans
}

