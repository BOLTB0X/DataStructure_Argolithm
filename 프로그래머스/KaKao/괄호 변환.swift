// 2020 KAKAO BLIND RECRUITMENT 괄호 변환
// https://school.programmers.co.kr/learn/courses/30/lessons/60058
import Foundation

func solution(_ p:String) -> String {
    var answer: String = ""
    
    if isBalancing(p) && isCollect(p) {
        answer = p
    } else if isBalancing(p) {
        answer = process(p)
    }
    
    return answer
}

func isBalancing(_ p: String) -> Bool {
    let p = p.map { String($0) }
    var cnt: Int = 0
    
    for element in p {
        if element == "(" { cnt += 1}
        else { 
            cnt -= 1
        }
    }
    
    return cnt > 0 ? false : true
}

func isCollect(_ p: String) -> Bool {
    let p = p.map { String($0) }
    var stack: [Int] = []
    
    for element in p {
        if element == "(" {
            stack.append(1)
        }
        else { 
            if stack.isEmpty {
                return false
            }
            
            stack.removeLast()
        }
    }
    
    return stack.isEmpty ? true : false
}

func process(_ p: String) -> String {
    if p.isEmpty { // 1
        return ""
    }
    
    let uv = splitedTwoString(p) // 2
    if isCollect(uv.0) { // 3
        return uv.0 + process(uv.1)
    }
    
    // 4
    var tmp = "("
    tmp += process(uv.1)
    tmp += ")"
    
    var u = uv.0.map{String($0)}
    u.removeFirst()
    u.removeLast()
    tmp += u.map{ $0 == "(" ? ")" : "(" }.joined()
    return tmp
}

func splitedTwoString(_ p: String) -> (String, String) {
    let p = p.map { String($0) }
    var u: String = ""
    var v: String = ""
    var openCount = 0
    var closeCount = 0
    
    for i in 0..<p.count {
        if p[i] == "(" {
            openCount += 1
        } else {
            closeCount += 1
        }
        
        if openCount != 0 && closeCount != 0 && openCount == closeCount {
            u = p[0...i].joined()
            v = p[i+1..<p.count].joined()
            break
        }
    }
    return (u, v)
}