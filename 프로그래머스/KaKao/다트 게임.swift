// 2018 KAKAO BLIND RECRUITMENT [1차] 다트 게임
// https://school.programmers.co.kr/learn/courses/30/lessons/17682

func solution(_ dartResult:String) -> Int {
    var answer: Int = 0
    var stack:[Int] = []
    let dartResult = dartResult.map { $0 }
    var tmp: String = ""
    
    for dart in dartResult {
        if let value = Int(String(dart)) {
            tmp.append(dart)
        } else {
            switch dart {
                case "S":
                stack.append(Int(tmp)!)
                break
                case "D":
                stack.append(Int(tmp)!*Int(tmp)!)
                break
                case "T":
                stack.append(Int(tmp)!*Int(tmp)!*Int(tmp)!)
                break
                case "*":
                if stack.count <= 1 {
                    let backFir = stack.removeLast()
                    stack.append(backFir * 2)
                } else {
                    let backFir = stack.removeLast()
                    let backSec = stack.removeLast()
                    stack.append(backSec * 2)
                    stack.append(backFir * 2)
                }
                break
                default:
                let ele = stack.removeLast()
                stack.append(ele * -1)
                break
            }
            tmp = ""
        }
    }
    //print(stack)
    answer = stack.reduce(0) { $0 + $1 }
    return answer
}