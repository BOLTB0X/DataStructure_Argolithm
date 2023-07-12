// 2019 카카오 개발자 겨울 인턴십 튜플
import Foundation

func transArray(_ s: String) -> [[String]] {
    var sArr = s.map{ String($0) }
    var stack: [Int] = []
    var arr:[[String]] = []
    var flag = false
    
    for i in 0..<sArr.count {
        if sArr[i] == "{" {
            flag = true
            stack.append(i)
        } else {
            if flag && sArr[i] == "}" {
                let lastIdx = i
                let stratIdx = stack.last!
                let partArr = Array(sArr[stratIdx...lastIdx])
                let newArr = partArr.filter { ele in
                    return Int(ele) != nil || ele == ","
                }
                
                if newArr.contains(",") {
                    let strArr = newArr.joined()
                    arr.append(strArr.components(separatedBy: ","))
                } else {
                    var tmp:String = ""
                    for n in newArr {
                        if n == "{" || n == "}" {
                            continue
                        }
                        tmp += n
                    }
                    arr.append([tmp])
                }
                
                flag = false
                stack.removeLast()
            } else if !flag && sArr[i] == "}" {
                stack.removeLast()
            }
        }
    }
    
    return arr
}

func solution(_ s:String) -> [Int] {
    var answer: [Int] = []
    var ret = transArray(s)
    //print(ret)
    
    let sortedRet = ret.sorted {
        $0.count < $1.count
    }
    //print(sortedRet)
    
    for ret in sortedRet {
        for r in ret {
            if answer.contains(Int(r)!) {
                continue
            }
            answer.append(Int(r)!)
        }
        
    }
    return answer
}