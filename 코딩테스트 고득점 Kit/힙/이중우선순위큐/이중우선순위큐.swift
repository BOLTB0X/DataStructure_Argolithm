import Foundation

func solution(_ operations:[String]) -> [Int] {
    var answer:[Int] = []
    var pq:[Int] = []
    
    for op in operations {
        let splitedOP = op.split(separator: " ")
        
        if splitedOP[0] == "I" {
            pq.append(Int(splitedOP[1])!)
            pq.sort(by: >)
        } else if splitedOP[0] == "D" {
            if pq.count > 0 && splitedOP[1] == "1" {
                pq.removeFirst()
            } else if pq.count > 0 && splitedOP[1] == "-1" {
                pq.removeLast()
            }
        }
    }
    
    if pq.count > 0 {
        answer = [pq.first!, pq.last!]
    } else {
        answer = [0, 0]
    }
    return answer
}