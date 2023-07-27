// 2020 KAKAO BLIND RECRUITMENT 괄호 변환
import Foundation

func solution(_ p:String) -> String {
    let answer:String = recurCourse(p)
    return answer
}

func recurCourse(_ p:String) -> String {
    if p.isEmpty { // 1
        return p
    }
    
    // 2
    let tmp = splitedBalance(p)
    //print(tmp)
    var u = tmp.0
    var v = tmp.1
    
    if isCorrect(u) { // 3
        return u + recurCourse(v) // 3-1
    } else {
        // 4
        var anotherTmpe = "" // 4-1
        anotherTmpe += "("
        anotherTmpe += recurCourse(v) // 4-2
        anotherTmpe += ")" // 4-3
        u.removeFirst()
        u.removeLast()
        //u = u.map{String($0)}.reversed().joined() // 4-4
        //print(anotherTmpe, u)
        // 4-4
        return anotherTmpe + u.map{String($0) == "(" ? ")" : "("}.joined()
    }
}

func splitedBalance(_ p: String) -> (String, String) {
    var u:String = ""
    var v:String = ""
    var openCnt:Int = 0
    var closeCnt:Int = 0
    let p = p.map { String($0) }
    
    for i in 0..<p.count {
        if p[i] == "(" {
            openCnt += 1
        } else {
            closeCnt += 1
        }
        
        if openCnt > 0 && closeCnt > 0 && openCnt == closeCnt {
            u = p[0...i].joined()
            v = p[i+1..<p.count].joined()
            break
        }
    }
    
    return (u, v)
}

func isCorrect(_ u:String) -> Bool {
    var stack: [Character] = []
    
    for ch in u {
        if ch == "(" {
            stack.append(ch)
        } else {
            if stack.isEmpty {
                return false
            }
            stack.removeLast()
        }
    }
    
    return stack.isEmpty
}