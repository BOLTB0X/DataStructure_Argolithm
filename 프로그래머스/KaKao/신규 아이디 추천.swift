// https://school.programmers.co.kr/learn/courses/30/lessons/72410
import Foundation

func solution(_ new_id:String) -> String {
    var answer: String = new_id
    
    answer = oneStep(answer)
    answer = twoStep(answer)
    answer = threeStep(answer)
    answer = fourStep(answer)
    answer = fiveStep(answer)
    answer = sixStep(answer)
    answer = sevenStep(answer)

    return answer
}

func oneStep(_ new_id: String) -> String {
    var ret: String = ""
    
    for ch in new_id {
        if ch.isUppercase {
            ret.append(ch.lowercased())
        } else {
            ret.append(ch)
        }
    }
    return ret
}

func twoStep(_ new_id: String) -> String {
    new_id.filter { $0.isLowercase || $0.isNumber || "-_.".contains($0) }.map {String($0) }.joined()
}

func threeStep(_ new_id: String) -> String {
    var ret: String = ""
    var flag: Bool = false
    
    for i in new_id {
        if i == "." {
            flag = true
        } else {
            if flag { ret.append(".") }
            ret.append(i)
            flag = false
        }
    }
    if flag { ret.append(".") }
    return ret
}

func fourStep(_ new_id: String) -> String {
    var new_id = new_id.map { String($0) }
    if new_id.count > 0 && new_id.first! == "." {
        new_id.removeFirst()
    }
    
    if new_id.count > 0 && new_id.last! == "." {
        new_id.removeLast()
    }
    
    return new_id.joined()
}

func fiveStep(_ new_id: String) -> String {
    if new_id.isEmpty {
        return "a"
    }
    return new_id
}

func sixStep(_ new_id: String) -> String {
    var new_id = new_id.map { String($0) }
    
    if new_id.count >= 16 {
        new_id = Array(new_id[0..<15])
    }
    
    if new_id.count > 0 && new_id.last! == "." {
        new_id.removeLast()
    }
    
    return new_id.joined()
}

func sevenStep(_ new_id: String) -> String {
    var new_id = new_id
    
    if new_id.isEmpty { return "" }
    
    while new_id.count <= 2 {
        new_id.append(new_id.last!)
    }
    return new_id
}