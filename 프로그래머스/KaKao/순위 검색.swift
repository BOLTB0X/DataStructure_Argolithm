// 2021 KAKAO BLIND RECRUITMENT 순위 검색
// https://school.programmers.co.kr/learn/courses/30/lessons/72412
import Foundation

func solution(_ info:[String], _ query:[String]) -> [Int] {
    var answer:[Int] = []
    let blockCase = combination([0,1,2,3], 4)
    let infoDict = createInfoDict(blockCase, info)
    
    for qry in query {
        let splitedQry = qry.components(separatedBy: " ")
        let findKey = "\(splitedQry[0])\(splitedQry[2])\(splitedQry[4])\(splitedQry[6])"
        let findValue = Int(splitedQry[7])!
        
        if let value = infoDict[findKey] {
            // 이분탐색
            var start:Int = 0
            var end:Int = value.count-1
            
            while start <= end {
                let mid = (start+end)/2
                
                if value[mid] < findValue {
                    start = mid + 1
                } else {
                    end = mid - 1
                }
            }
            // 1 2 3
            answer.append(value.count - start)
        } else {
            answer.append(0)
        }
    }
    
    return answer
}

func combination(_ n: [Int], _ r: Int) -> [[Int]] {
    var ret: [[Int]] = []
    
    func DFS(_ com:[Int], _ cur:Int, _ depth:Int, _ limit: Int) {
        if depth == limit {
            ret.append(com)
            return
        }
        
        for i in cur..<n.count {
            DFS(com + [n[i]], i+1, depth + 1, limit)
        }
    }
    
    for i in 0...r {
        DFS([], 0, 0, i)
    }
    
    return ret
}

func createInfoDict(_ blockCase: [[Int]], _ info:[String]) -> [String:[Int]] {
    var ret: [String:[Int]] = [:]
    
    for com in blockCase {
        for inf in info {
            var splitedInf = inf.components(separatedBy: " ")
            
            com.forEach { c in
                splitedInf[c] = "-"
            }
            
            ret["\(splitedInf[0])\(splitedInf[1])\(splitedInf[2])\(splitedInf[3])", default: []] += [Int(splitedInf[4])!] 
        }
    }
    
    for (key, value) in ret {
        ret[key] = value.sorted()
    }
    
    return ret
}