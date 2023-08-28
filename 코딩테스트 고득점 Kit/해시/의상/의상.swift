import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var answer: Int = 1 
    var dic:[String: Int] = [:]


    for clothe in clothes {
        if let _ = dic[clothe[1]] {
            dic[clothe[1]]? += 1
        } else {
            dic[clothe[1]] = 1
        }
    }
    
    for (ket, value) in dic {
        answer *= (value+1)
    }
    
    
    return answer-1
}