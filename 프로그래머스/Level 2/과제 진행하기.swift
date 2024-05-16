import Foundation

func solution(_ plans:[[String]]) -> [String] {
    var answer: [String] = []
    var que = plans.reduce(into: [(String, Int, Int)]()) {
        $0 += [($1[0], convertTotalSeconds($1[1]), Int($1[2])!)]
    }.sorted { $0.1 < $1.1 }
    var qIdx: Int = 0
    var stack: [(String, Int, Int)] = Array(repeating: ("", 0, 0), count: 1001)
    var sIdx: Int = -1
    var sec: Int = 0
    
    while qIdx < que.count {
        let cur = que[qIdx]
        qIdx += 1
        
        while sec < cur.1 {
            if sIdx > -1 {
                stack[sIdx].2 -= 1
                
                if stack[sIdx].2 == 0 {
                    answer.append(stack[sIdx].0)
                    sIdx -= 1
                }
            }
            sec += 1
        }
        
        sIdx += 1
        stack[sIdx] = cur
    }
    
    while sIdx > -1 {
        answer.append(stack[sIdx].0)
        sIdx -= 1
    }
    
    return answer
}

func convertTotalSeconds(_ str: String) -> Int {
    let splitedStr = str.components(separatedBy: ":")
    return Int(splitedStr[0])! * 60 + Int(splitedStr[1])!
}