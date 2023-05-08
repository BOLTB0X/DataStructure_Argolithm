import Foundation

func solution(_ s:String) -> Bool {   
    let _s = Array(s) // 편의상
    var bracketCount = 0

    for ch in _s {
        // 열림이면 
        if ch == "(" {
            bracketCount += 1
        } else { // 닫힘이면
            bracketCount -= 1
        }
        
        // 만약 괄호가 0보다 작아지면 즉, 괄호가 맞지 않다는 뜻
        if bracketCount < 0 {
           return false
        }
    }
    
    // 다 끝난후에도 괄호가 남아있다면
    if bracketCount != 0 {
        return false
    }

    return true
}